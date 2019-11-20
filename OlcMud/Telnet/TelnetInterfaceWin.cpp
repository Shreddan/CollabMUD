
#ifdef _WIN32

#include "TelnetInterface.hpp"


TelnetInterface::TelnetInterface()
{
    

}

TelnetInterface::~TelnetInterface()
{

}


void TelnetInterface::Initialise()
{
	struct addrinfo *result = NULL;
	addrinfo hints;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(NULL, "23", &hints, &result);

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) 
	{
		std::cout << "Error at socket() : " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		WSACleanup();
	}

	//listen(ListenSocket, SOMAXCONN);

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) 
	{
		std::cout << "bind failed with error : " << WSAGetLastError() << std::endl;
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
	}

	freeaddrinfo(result);
}

void TelnetInterface::waitForConn(std::string& IntroSeq)
{
	ClientSocket = INVALID_SOCKET;
	while (ClientSocket == INVALID_SOCKET)
	{
		listen(ListenSocket, SOMAXCONN);
		ClientSocket = accept(ListenSocket, NULL, NULL);
	}
	if (ClientSocket == INVALID_SOCKET) {
		std::cout << "accept failed" << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
	}
	else
	{
		std::cout << "Connection Established" << std::endl;
	}

	
	
}

void TelnetInterface::SendIntro(std::string& IntroSeq, SOCKET ClientSocket)
{
	send(ClientSocket, IntroSeq.c_str(), IntroSeq.size(), 0);
}

#endif
