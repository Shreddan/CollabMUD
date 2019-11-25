#pragma once 

#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#endif

#ifdef __linux__

#include <sys/socket.h>
#include <sys/types.h> 
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#endif

#include <iostream>
#include <string>
#include <thread>

#include "TelnetHelpers.hpp"

struct TCPSocket
{

#ifdef _WIN32
	SOCKET Socket;
	WSADATA WSAData;
#endif

#ifdef __linux__
	int Socket;
	struct sockaddr_in Address;
#endif

	unsigned short int Port;

};


struct TelnetListenSocket : public TCPSocket
{

};

struct ClientSocket : public TCPSocket 
{

};


// Telnet implementations 
// Somewhat high level
// OS agnostic
class TelnetInterface
{
public:

    TelnetInterface();
	~TelnetInterface();

	// Initialise the listening socket
	void Init();

	// Does not return, do not call 
	// on main thread
	void Listen();

	TelnetListenSocket* TelnetListen = nullptr;

    // Not up to the telnet interface
    // to give connections threads (?)
    // ^^ subject to change

private:

	bool mEscapeListen = false;
	bool mFailed = false;

};
