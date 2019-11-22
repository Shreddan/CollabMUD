#pragma once

#include "../Telnet/TelnetInterface.hpp"

#include <thread>
#include <mutex>

class NetworkInterface
{
public:
	NetworkInterface();
	~NetworkInterface();

	void Init();
	void Listen();

private:
	
	TelnetInterface mTelnetInterface;

	// Listening thread
	std::thread mListenThread;
	void mListenThreadEx();
	std::mutex mShouldStartListeningMutex;
	bool mShouldStartListening = false;


};

