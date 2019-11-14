#include <Windows.h>
#include <iostream>
#include <iomanip>

#define CSI "\x1b["
#define GREEN "38;5;46m"
#define RED "38;5;124m"
#define YELLOW "38;5;226m"
#define BLUE "38;5;27m"
#define CYAN "38;5;51m"
#define MAGENTA "38;5;164m"
#define WHITE "38;5;254m"

int main()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	std::cout << CSI << GREEN << "Your actions will appear in Green" << std::endl;
	std::cout << CSI << RED << "Enemy actions will appear in Red" << std::endl;
	std::cout << CSI << YELLOW << "NPC actions will appear in Yellow" << std::endl;
	std::cout << CSI << BLUE << "Magic actions will appear in Blue" << std::endl;
	std::cout << CSI << CYAN << "Positive status affects will appear in Cyan" << std::endl;
	std::cout << CSI << MAGENTA << "Negative status affects will appear in Magenta" << std::endl;
	std::cout << CSI << WHITE << "All other text will appear in white" << std::endl;

	getchar();

	return 0;

}

