#ifdef __linux__

#include "TelnetInterface.hpp"

#include <cstring>
#include <memory>
#include <string>

TelnetInterface::TelnetInterface()
{
    

}


void TelnetInterface::Initialise() 
{

    if (TelnetListen != nullptr)
        return;

    TelnetListen = new TelnetListenSocket();

    struct sockaddr_in serverAddrees;

    TelnetListen->Socket = socket(AF_INET, SOCK_STREAM, 0);
    TelnetListen->Port = 23;
    
    if (TelnetListen->Socket < 0) 
    {

        std::cout << "ERROR: Something went wrong when creating a telnet listen socket" << std::endl;
        delete TelnetListen;
        return;

    }



}

void TelnetInterface::Listen() 
{

}

TelnetInterface::~TelnetInterface() 
{



}

#endif
