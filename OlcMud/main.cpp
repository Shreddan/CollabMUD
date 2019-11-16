#include "MudEngine.hpp"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

int main( int argc, char** argv )
{
	MudEngine mud;

	SettupANSI();

	std::cout << "Welcome to the CollabMud v" << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	mud.Intro();

	getchar();

	return 0;

}

