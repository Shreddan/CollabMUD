#include "MudEngine.h"

MudEngine::MudEngine()
{

}

MudEngine::~MudEngine()
{

}

void MudEngine::Intro()
{
	int numofplr = 0;
	std::cout << CSI << WHITE << "><=========================================================================><\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||" << CSI << GREEN << "                        Welcome to UnNamedMud                            " << CSI << WHITE << "||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "||" << CSI << MAGENTA << "   There are " << CSI << CYAN << numofplr << CSI << MAGENTA << " Players Online                                            " << CSI << WHITE << "||\n";
	std::cout << CSI << WHITE << "||                                                                         ||\n";
	std::cout << CSI << WHITE << "><=========================================================================><\n";
}
