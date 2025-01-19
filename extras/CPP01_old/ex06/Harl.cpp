#include "Harl.hpp"

#include <iostream>
#include <string>

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

/* public: */

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


void Harl::complain(std::string level) const
{
	int MAX = 4;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) const = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::transform(level.begin(), level.end(), level.begin(), toupper);

	for (int i = 0; i < MAX; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "There is no such command:" << " " << level << std::endl;
	return;
}

int Harl::getLevel(std::string level) const
{
	int MAX = 4;
	std::string levels[] = {"DEBUG",
							"INFO",
							"WARNING",
							"ERROR"};
	std::transform(level.begin(), level.end(), level.begin(), toupper);
	for (int i = 0; i < MAX; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}
