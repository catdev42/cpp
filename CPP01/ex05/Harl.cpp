#include "Harl.hpp"

#include <iostream>
#include <cctype>

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
	_debugVar = "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				"I really do!";

	_infoVar = "I cannot believe adding extra bacon costs more money.\n"
			   "You didn't put enough bacon in my burger! "
			   "If you did, I wouldn't be asking for more!";

	_warningVar = "I think I deserve to have some extra bacon for free.\n"
				  "I've been coming for years whereas you started working "
				  "here since last month.";

	_errorVar = "This is unacceptable! "
				"I want to speak to the manager now.";
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
	std::cout << "[ Probably complaining about insignificant problems ] : " << " \'" << level << "'" <<std::endl;
	return;
}
