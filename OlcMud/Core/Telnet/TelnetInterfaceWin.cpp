
#ifdef _WIN32

#include "TelnetInterface.hpp"


TelnetInterface::TelnetInterface()
{
    

}

void TelnetInterface::Init()
{

	if ( TelnetListen != nullptr )
		return;

	TelnetListen = new TelnetListenSocket();

	TelnetListen->Port = 23;

	struct addrinfo *result = NULL;
	addrinfo hints;

	int iResult = WSAStartup( MAKEWORD(2, 2), &TelnetListen->WSAData );

	ZeroMemory( &hints, sizeof( hints ) );
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo( NULL, "23", &hints, &result );

	TelnetListen->Socket = socket( result->ai_family, result->ai_socktype, result->ai_protocol );

	if ( TelnetListen->Socket == INVALID_SOCKET ) 
	{
		std::cout << "ERROR: Something went wrong when creating a telnet listen socket : " << WSAGetLastError() << std::endl;
		freeaddrinfo( result );
		WSACleanup();
		delete TelnetListen;
		mFailed = true;
		return;
	}

	iResult = bind( TelnetListen->Socket, result->ai_addr, (int)result->ai_addrlen );

	if ( iResult == SOCKET_ERROR ) 
	{
		std::cout << "ERROR: Something went wrong when binding the telnet listen socket : " << WSAGetLastError() << std::endl;
		freeaddrinfo( result );
		closesocket( TelnetListen->Socket );
		WSACleanup();
		delete TelnetListen;
		mFailed = true;
		return;
	}

	freeaddrinfo( result );

	std::cout << "Socket Created" << std::endl;

}

void TelnetInterface::Listen()
{

	if ( mFailed ) return;

	std::cout << "Socket Listening" << std::endl;

	while ( !mEscapeListen )
	{

		ClientSocket clientSocket;
		clientSocket.Socket = INVALID_SOCKET;

		while ( clientSocket.Socket == INVALID_SOCKET )
		{
			listen( TelnetListen->Socket, SOMAXCONN );
			clientSocket.Socket = accept( TelnetListen->Socket, NULL, NULL );
		}

		std::cout << "Connection Established" << std::endl;
		send( clientSocket.Socket, "Bruh", std::string( "Bruh" ).size(), 0 );
		closesocket( clientSocket.Socket );

	}

}

TelnetInterface::~TelnetInterface()
{
	closesocket( TelnetListen->Socket );
	WSACleanup();
	delete TelnetListen;
	mFailed = true;
}

#endif
