#pragma once

#include "Core/Network/NetworkInterface.hpp"
#include "Core/Commands/Commands.hpp"

#include "Util/ConsoleANSI.hpp"

class MudEngine
{
public:
	MudEngine();
	~MudEngine();

	void NetInit();
	void GameInit();

	void Ready();

	void TempMessage(std::string &temp);

	std::string temp;

private:
	NetworkInterface mNetworkInterface;
	Commands mCommands;
};

