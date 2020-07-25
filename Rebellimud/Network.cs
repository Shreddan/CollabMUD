using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using System.Threading;


namespace Rebellimud
{
    class Network
    {
        private static byte[] buffer = new byte[1024];
        private static List<Socket> clientSockets = new List<Socket>();
        private static Socket serverSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        private static string response = string.Empty;

        

        public static void Setup()
        {
            Console.WriteLine("Setting up Server");
            Users.Setup();
            serverSock.Bind(new IPEndPoint(IPAddress.Any, 100));
            serverSock.Listen(10);
            serverSock.BeginAccept(new AsyncCallback(AcceptCallBack), null);
        }

        private static void AcceptCallBack(IAsyncResult ar)
        {
            Socket socket = serverSock.EndAccept(ar);
            clientSockets.Add(socket);
            Console.WriteLine("Client Connected");
            socket.BeginReceive(buffer, 0, buffer.Length, SocketFlags.None, new AsyncCallback(ReceiveCallBack), socket);
            serverSock.BeginAccept(new AsyncCallback(AcceptCallBack), null);
        }

        private static void ReceiveCallBack(IAsyncResult ar)
        {
            try
            {
                Socket socket = (Socket)ar.AsyncState;
                int received = socket.EndReceive(ar);
                byte[] dBuf = new byte[received];
                Array.Copy(buffer, dBuf, received);
                string text = Encoding.ASCII.GetString(dBuf);
                Console.WriteLine("Text Received : " + text);

                Parse(text, socket);

                byte[] data = Encoding.ASCII.GetBytes(response);
                socket.BeginSend(data, 0, data.Length, SocketFlags.None, new AsyncCallback(SendCallBack), socket);
                socket.BeginReceive(buffer, 0, buffer.Length, SocketFlags.None, new AsyncCallback(ReceiveCallBack), socket);
            }
            catch (SocketException e)
            {
                Console.WriteLine(e);
            }
        }

        private static void SendCallBack(IAsyncResult ar)
        {
            Socket socket = (Socket)ar.AsyncState;
            socket.EndSend(ar);
        }

        private static void Parse(string text, Socket socket)
        {
            text = text.ToLower();
            string[] temptext = text.Split(" ");

            switch (temptext[0])
            {
                case "register":
                    {
                        Users.InsertTable(temptext[1], temptext[2], temptext[3]);
                        response = Users.ReadTable();
                        break;
                    }

                case "login":
                    {
                        bool temp = Users.CheckTable(temptext[1]);
                        if (!temp)
                        {
                            response = "<001>User does not Exist";
                        }
                        else
                        {
                            response = Users.ReadTable(temptext[1]);
                        }
                        
                        break;
                    }

                case "time":
                    {
                        response = "<001>" + DateTime.Now.ToLongTimeString();
                        break;
                    }

                case "clients":
                    {
                        response = "<001>" + clientSockets.Count.ToString();
                        break;
                    }

                case "quit":
                    {
                        response = "<002>Quitting.........";
                        socket.Close();
                        break;
                    }

                case "user":
                    {
                        var str = temptext[1];
                        var name = Users.ReadTable(str);
                        response = "<003>" + name;
                        break;
                    }

                default:
                    {
                        response = "<002>Invalid Command";
                        break;
                    }

            }

        }
    }
}

