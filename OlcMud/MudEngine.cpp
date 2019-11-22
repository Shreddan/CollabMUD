#include "MudEngine.hpp"

MudEngine::MudEngine()
	: mNetworkInterface()
{

}

void MudEngine::NetInit()
{

	mNetworkInterface.Init();

	listenthread.join();

}

void MudEngine::GameInit()
{

}

void MudEngine::Ready()
{
	
	mNetworkInterface.Listen();

}

MudEngine::~MudEngine()
{

}
