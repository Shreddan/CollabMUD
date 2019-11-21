#pragma once 

#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#endif

#ifdef __linux__

#include <sys/socket.h>

#endif

#include <iostream>
#include <string>
#include <thread>

#include "TelnetHelpers.hpp"

struct TCPSocket
{

#ifdef _WIN32
	SOCKET Socket;
	int Port;
#endif

#ifdef __linux__
	int Socket;
	int Port;
#endif
	
};


struct TelnetListenSocket : public TCPSocket
{

};

struct Clientsocket : public TCPSocket 
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
	void Initialise();

	// Does not return, do not call 
	// on main thread
	void Listen();

	TelnetListenSocket TelnetListen;

    // Not up to the telnet interface
    // to give connections threads (?)
    // ^^ subject to change


};
