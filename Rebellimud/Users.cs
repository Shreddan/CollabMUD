using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Data.Sqlite;

namespace Rebellimud
{
    class Users
    {
        public static SqliteConnectionStringBuilder connectionStringBuilder;
        public static SqliteConnection conn;
        public static SqliteCommand delTable;
        public static SqliteCommand createTable;
        public static SqliteCommand checkTable;
        public static SqliteCommand insertTable;
        public static SqliteCommand selectTable;
        public static SqliteTransaction transaction;
        public static string message = string.Empty;

        public static void Setup()
        {
            connectionStringBuilder = new SqliteConnectionStringBuilder();
            connectionStringBuilder.DataSource = "./User.db";
            OpenDB();
        }

        public static void OpenDB()
        {
            Console.WriteLine("Checking Database.....");
            using (conn = new SqliteConnection(connectionStringBuilder.ConnectionString))
            {
                conn.Open();
                CheckExist();
            }
        }

        public static void CheckExist()
        {
            try
            {
                delTable = conn.CreateCommand();
                delTable.CommandText = "DROP TABLE IF EXISTS User";
                var num = delTable.ExecuteNonQuery();
                Console.WriteLine("Entries changed : " + num);
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
            }
        }

        public static void CreateTable()
        {
            try
            {
                createTable = conn.CreateCommand();
                createTable.CommandText = "CREATE TABLE User(name VARCHAR(12), ID , pass VARCHAR(12), level int, class char(12))";
                createTable.ExecuteNonQuery();
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
            }
        }

        public static void CheckTable()
        {
            checkTable = conn.CreateCommand();
            checkTable.CommandText = "WHERE";
        }

        public static void InsertTable(string name, string pass, string aclass)
        {
            try
            {
                using (transaction = conn.BeginTransaction())
                {
                    insertTable = conn.CreateCommand();

                    insertTable.CommandText = "INSERT INTO User VALUES(" + name + "," + pass + ", 1, " + aclass + ")";
                    var num = insertTable.ExecuteNonQuery();
                    Console.WriteLine("Entries changed : " + num);

                    transaction.Commit();
                }
            }
            catch (SqliteException e)
            {
                Console.WriteLine(e);
            }
        }

        public static void ReadTable()
        {
            try
            {
                selectTable = conn.CreateCommand();
                selectTable.CommandText = "SELECT * FROM USER";

                using (var reader = selectTable.ExecuteReader())
                {
                    var i = 0;
                    while (reader.Read())
                    {
                        message = reader.GetString(i);
                        Console.WriteLine(message);
                        i++;
                    }
                }
            }
            catch(SqliteException e)
            {
                Console.WriteLine(e);
            }

        }

        public static string ReadTable(string tableName)
        {
            try
            {
                selectTable = conn.CreateCommand();
                selectTable.CommandText = "SELECT" + tableName + " FROM USER";

                using (var reader = selectTable.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        message = reader.GetString(0);
                    }
                    return message;
                }
            }
            catch(SqliteException e)
            {
                Console.WriteLine(e);
                return string.Empty;
            }
        }

        public static void CloseDB()
        {
            conn.Close();
        }
    }
}
