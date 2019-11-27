#pragma once
#include <iostream>
#include <regex>

class Commands
{
public:
	Commands();
	~Commands();

	std::smatch regexify(std::string &sent);

	void commandlist(std::smatch &sm);

	std::smatch sm;

	bool Close;
};