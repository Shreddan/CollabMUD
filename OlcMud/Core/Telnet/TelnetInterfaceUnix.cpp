#ifdef __linux__

#include "TelnetInterface.hpp"

#include <cstring>
#include <memory>
#include <string>

TelnetInterface::TelnetInterface()
{
    

}


void TelnetInterface::Init() 
{

    if ( TelnetListen != nullptr )
        return;

    TelnetListen = new TelnetListenSocket();

    TelnetListen->Socket = socket( AF_INET, SOCK_STREAM, 0 );
    TelnetListen->Port = 23;
    
    if (TelnetListen->Socket < 0) 
    {

        std::cout << "ERROR: Something went wrong when creating a telnet listen socket" << std::endl;
        delete TelnetListen;
        return;

    }

    memset(&TelnetListen->Address, 0, sizeof(TelnetListen->Address));

	TelnetListen->Address.sin_family = AF_INET;
	TelnetListen->Address.sin_addr.s_addr = htonl(INADDR_ANY);
	TelnetListen->Address.sin_port = htons(23);

    bind(TelnetListen->Socket, (struct sockaddr*)&TelnetListen->Address, sizeof(TelnetListen->Address));

}

void TelnetInterface::Listen() 
{

    listen(TelnetListen->Socket, 200);

	std::cout << "Socket Listening" << std::endl;

    while (!mEscapeListen)
    {

        ClientSocket client;
        client.Socket = accept(TelnetListen->Socket, (struct sockaddr*)NULL, NULL);

        write(client.Socket, (void*)"Bruh", std::string("Bruh").size());
        close(client.Socket);

    }

}

TelnetInterface::~TelnetInterface() 
{

    mEscapeListen = true;

}

#endif
