#pragma once


#include <iomanip>
#include "Core/Network/NetworkInterface.hpp"
#include "ANSI.hpp"

class MudEngine
{
public:
	MudEngine();
	~MudEngine();

	void NetInit();
	void GameInit();

	void Ready();


private:
	NetworkInterface mNetworkInterface;

};

