#include "MudEngine.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

int main( int argc, char** argv )
{
	MudEngine mud;

	std::cout << "Welcome to the CollabMud v" << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
	std::cout << std::endl;

	mud.Intro();

	getchar();

	return 0;

}

