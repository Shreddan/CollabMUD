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
	mCommands.items.addWeapons(mCommands.items.weapons);
	while (!mCommands.Close)
	{
		std::getline(std::cin, temp);
		TempMessage(temp);
	}
}

void MudEngine::TempMessage(std::string & temp)
{
	mCommands.regexify(temp);
	mCommands.commandlist(mCommands.sm);
}


