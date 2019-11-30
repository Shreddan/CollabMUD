
#ifdef _WIN32

#include "TelnetInterface.hpp"

#include "TelnetConnectionManager.hpp"

TelnetInterface::TelnetInterface()
{
    

}

void TelnetInterface::Init( TelnetConnection* telnetConnection )
{

	if ( TelnetListen != nullptr )
		return;

	mTelnetConnection = telnetConnection;

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

		ClientSocket client;
		client.Socket = INVALID_SOCKET;

		int addrlen = sizeof( client.Address );

		while ( client.Socket == INVALID_SOCKET )
		{
			listen( TelnetListen->Socket, SOMAXCONN );
			client.Socket = accept( TelnetListen->Socket, (SOCKADDR*)&client.Address, &addrlen );
		}

		std::string ip = static_cast<std::string>( inet_ntoa( client.Address.sin_addr ) );

		std::cout << "Connection Established : " << ip << std::endl;
		
		send( client.Socket, "Welcome To CollabMud\n", std::string( "Welcome To CollabMud\n" ).size(), 0 );

#define DEFAULT_BUFLEN 512

		char recvbuf[DEFAULT_BUFLEN];
		int iResult, iSendResult;
		int recvbuflen = DEFAULT_BUFLEN;

		// Receive until the peer shuts down the connection
		do {

			iResult = recv( client.Socket, recvbuf, recvbuflen, 0 );
			if ( iResult > 0 ) {
				printf( "Bytes received: %d\n", iResult );

				// Echo the buffer back to the sender
				iSendResult = send( client.Socket, recvbuf, iResult, 0 );
				if ( iSendResult == SOCKET_ERROR ) {
					printf( "send failed: %d\n", WSAGetLastError() );
					closesocket( client.Socket );
					WSACleanup();
					return;
				}
				printf( "Bytes sent: %d\n", iSendResult );
			}
			else if ( iResult == 0 )
				printf( "Connection closing...\n" );
			else {
				printf( "recv failed: %d\n", WSAGetLastError() );
				closesocket( client.Socket );
				WSACleanup();
				return;
			}

		} while ( iResult > 0 );

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
