#include "MudEngine.h"

MudEngine::MudEngine()
{

}

MudEngine::~MudEngine()
{

}

void MudEngine::Intro()
{
	std::cout << CSI << WHITE << "><-------------------------------------------------------------------------><" << std::endl;
	std::cout << CSI << GREEN << "||Welcome to CollabMud||" << std::endl;
	std::cout << CSI << WHITE << "><-------------------------------------------------------------------------><" << std::endl;
}
