#ifdef __linux__

#include "TelnetInterface.hpp"

#include <cstring>
#include <memory>
#include <string>

TelnetInterface::TelnetInterface()
{
    

}


void TelnetInterface::Init(TelnetConnection* telnetConnection) 
{

    if ( TelnetListen != nullptr )
        return;

    mTelnetConnection = telnetConnection;

    TelnetListen = new TelnetListenSocket();
    TelnetListen->Address = sockaddr_in();

    TelnetListen->Socket = socket( AF_INET, SOCK_STREAM, 0 );
    TelnetListen->Port = static_cast<unsigned short int>( 23 );
    
    if ( TelnetListen->Socket < 0 ) 
    {

        std::cout << "ERROR: Something went wrong when creating the telnet listen socket" << std::endl;
        delete TelnetListen;
        mFailed = true;
        return;

    }

    memset( &TelnetListen->Address, 0, sizeof( TelnetListen->Address ) );

	TelnetListen->Address.sin_port = htons( static_cast<unsigned short int>( TelnetListen->Port ) );
	TelnetListen->Address.sin_family = AF_INET;
	TelnetListen->Address.sin_addr.s_addr = htonl(INADDR_ANY);

    int status = bind( TelnetListen->Socket, (struct sockaddr*)&TelnetListen->Address, sizeof( TelnetListen->Address ) );

    if ( status != 0 )
    {

        std::cout << "ERROR: Something went wrong when binding the telnet listen socket : " << errno << std::endl;
        delete TelnetListen;
        mFailed = true;
        return;

    }
	
	std::cout << "Socket Created" << std::endl;

}

void TelnetInterface::Listen() 
{

    if ( mFailed ) return;

    listen( TelnetListen->Socket, 200 );

	std::cout << "Socket Listening" << std::endl;

    while ( !mEscapeListen )
    {

        ClientSocket client;

		int addrlen = sizeof( client.Address );
        client.Socket = accept( TelnetListen->Socket, (struct sockaddr*)&client.Address, (socklen_t*)&addrlen );
		
		char* ip = new char[INET_ADDRSTRLEN];
        // Get clients ip
		// inet_ntop( AF_INET, &client.Address->sin_addr, ip, sizeof( ip ) );
		
		std::cout << "Connection Established" << std::endl;

        write( client.Socket, (void*)"Welcome To CollabMud\n", std::string( "Welcome To CollabMud\n" ).size() );

        

        close( client.Socket );

        delete ip;

    }

}

TelnetInterface::~TelnetInterface() 
{

    mEscapeListen = true;

}

#endif
