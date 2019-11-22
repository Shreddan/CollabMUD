#include "NetworkInterface.hpp"

NetworkInterface::NetworkInterface()
	: mTelnetInterface()
{

}

void NetworkInterface::Init()
{

	mTelnetInterface.Init();

	mListenThread = std::thread([&]() {
		mListenThreadEx();
	});

}

void NetworkInterface::Listen()
{

	mShouldStartListeningMutex.lock();
	mShouldStartListening = true;
	mShouldStartListeningMutex.unlock();

}

void NetworkInterface::mListenThreadEx()
{

	while (!mShouldStartListening)
	{
		static std::chrono::milliseconds dura(1);
		std::this_thread::sleep_for(dura);
	}

	mTelnetInterface.Listen();
}

NetworkInterface::~NetworkInterface() 
{

	// Cannot join as listen thread never exits
	// TODO: dont do this
	mListenThread.detach();

}
