#include "MudEngine.hpp"

MudEngine::MudEngine()
	: mNetworkInterface()
{

}

MudEngine::~MudEngine()
{

}

void MudEngine::NetInit()
{

	GameInit();
	mNetworkInterface.Init();

}

void MudEngine::GameInit()
{

}

void MudEngine::Ready()
{
	
	mNetworkInterface.Listen();
	
}

void MudEngine::TempMessage(std::string & temp)
{
	mCommands.regexify(temp);
	mCommands.commandlist(mCommands.sm);
}


