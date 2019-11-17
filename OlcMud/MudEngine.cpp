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
	tel1.waitForConn();
	if (tel1.ClientSocket != INVALID_SOCKET)
	{
		tel1.SendIntro(IntroSeq, tel1.ClientSocket);
	}
}