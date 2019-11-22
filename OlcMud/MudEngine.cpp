#include "MudEngine.hpp"

MudEngine::MudEngine()
	: mNetworkInterface()
{

}

void MudEngine::NetInit()
{

	mNetworkInterface.Init();

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
