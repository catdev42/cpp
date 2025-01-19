#include "Harl.hpp"

#include <iostream>
#include <cctype>

// private:
// 	std::string _debugVar;
// 	std::string _infoVar;
// 	std::string _warningVar;
// 	std::string _errorVar;

// public:

static void make_lower(std::string &str)
{
	for (std::string::iterator it= str.begin(); it < str.end(); it++)
		*it = static_cast<char>(std::tolower(static_cast<unsigned char>(*it)));
	return;
}

static void make_upper(std::string &str)
{
	for (std::string::iterator it= str.begin(); it < str.end(); it++)
		*it = static_cast<char>(std::toupper(static_cast<unsigned char>(*it)));
	return;
}

Harl::Harl()
{
	_debugVar = "Writing debug message";
	_infoVar = "Writing info message";
	_warningVar = "Writing warning message";
	_errorVar = "Writing error message";
	return;
}
Harl::~Harl()
{
	return;
}

void Harl::debug(void) const
{
	std::cout << _debugVar << std::endl;
	return;
}
void Harl::info(void) const
{
	std::cout << _infoVar << std::endl;
	return;
}
void Harl::warning(void) const
{
	std::cout << _warningVar << std::endl;
	return;
}
void Harl::error(void) const
{
	std::cout << _errorVar << std::endl;
	return;
}

void Harl::complain(std::string level) const
{
	int MAX = 4;

	std::string levels[] = {"debug", "info", "warning", "error"};
	void (Harl::*functions[])(void) const = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	make_lower(level);

	for (int i = 0; i < MAX; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
	make_upper(level);
	std::cout << "There is no such command:" << " \'" << level << "'" <<std::endl;
	return;
}
