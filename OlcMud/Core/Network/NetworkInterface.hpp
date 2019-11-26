#pragma once

#include "../Telnet/TelnetConnectionManager.hpp"
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

	// Telnet connection manager
	// manages communications with
	// active connections to the server
	TelnetConnection mTelnetConnection;
	
	TelnetInterface mTelnetInterface;

	// Listening thread
	std::thread mListenThread;
	void mListenThreadEx();
	std::mutex mShouldStartListeningMutex;
	bool mShouldStartListening = false;


};

