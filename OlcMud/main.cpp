#include "MudEngine.hpp"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

// TODO: Logging system

int main( int argc, char** argv )
{
	MudEngine mudEngine;

	SettupANSI();

	std::cout << "Welcome to the CollabMud v"
		<< VERSION_MAJOR << "." << VERSION_MINOR
		<< std::endl << std::endl << std::endl;

	mudEngine.NetInit();
	mudEngine.Ready();

	std::cout << "Ready!" << std::endl;

	// Prevent closing
	getchar();

	return 0;

}

