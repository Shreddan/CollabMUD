#pragma once


#include <iomanip>


#include "Telnet/TelnetInterface.hpp"
#include "ANSI.hpp"

class MudEngine
{
public:
	MudEngine();
	~MudEngine();


	void Intro();

	void Loop();
	std::thread listenthread;

	std::string IntroSeq;

	TelnetInterface tel1;
};

