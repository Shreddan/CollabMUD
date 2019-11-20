#include "MudEngine.hpp"

MudEngine::MudEngine()
{

}

MudEngine::~MudEngine()
{

}

void MudEngine::Intro()
{
	int numofplr = 0;
	IntroSeq = CSI WHITE "><=========================================================================><\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||";
	IntroSeq += CSI GREEN "                        Welcome to UnNamedMud                            ";
	IntroSeq += CSI WHITE "||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "||";
	IntroSeq += CSI MAGENTA "   There are ";
	IntroSeq += CSI CYAN + std::to_string(numofplr);
	IntroSeq += CSI MAGENTA " Players Online                                            ";
	IntroSeq += CSI WHITE "||\n";
	IntroSeq += CSI WHITE "||                                                                         ||\n";
	IntroSeq += CSI WHITE "><=========================================================================><\n";

	tel1.Initialise();
	std::thread listenthread(&TelnetInterface::waitForConn, &tel1);
	tel1.SendIntro(IntroSeq, tel1.ClientSocket);
	Loop();
}

void MudEngine::Loop()
{
	
}