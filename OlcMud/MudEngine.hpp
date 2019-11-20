#pragma once


#include <iomanip>
#include <thread>


#include "Telnet/TelnetInterface.hpp"
#include "ANSI.hpp"

class MudEngine
{
public:
	MudEngine();
	~MudEngine();


	void Intro();

	void Loop();

	std::string IntroSeq;

	TelnetInterface tel1;
};

