#pragma once

#ifdef _WIN32
#include <windows.h>
#endif

#define CSI "\x1b["
#define GREEN "38;5;46m"
#define RED "38;5;124m"
#define YELLOW "38;5;226m"
#define BLUE "38;5;27m"
#define CYAN "38;5;51m"
#define MAGENTA "38;5;164m"
#define WHITE "38;5;254m"

inline void SettupANSI()
{

#ifdef _WIN32
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif

}
