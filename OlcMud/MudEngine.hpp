#pragma once

#include "Core/Network/NetworkInterface.hpp"

#include "Util/ConsoleANSI.hpp"

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

