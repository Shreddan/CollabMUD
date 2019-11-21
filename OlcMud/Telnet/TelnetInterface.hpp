#pragma once 

// Maybe singleton model for this?
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


class TelnetInterface
{
public:

    TelnetInterface();
	~TelnetInterface();

    // Telnet implementations 
    // Somewhat high level
    // OS agnostic

	//Winsock init
	void Initialise();

	void waitForConn();

	void SendIntro(std::string& IntroSeq, SOCKET ClientSocket);

	SOCKET ListenSocket;
	SOCKET ClientSocket;

	int GetiResult() { return iResult; }
	int GetiSend() { return iSendResult; }
    // Not up to the telnet interface
    // to give connections threads (?)
    // ^^ subject to change

private:
	WSADATA wsadata;
	int iResult;
	int iSendResult;


};
