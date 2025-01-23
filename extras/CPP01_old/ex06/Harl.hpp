#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	std::string _debugVar;
	std::string _infoVar;
	std::string _warningVar;
	std::string _errorVar;
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;

public:
	Harl();
	~Harl();

	void complain(std::string level) const;
	int getLevel(std::string level) const;
};

void harlFilter(std::string level, Harl &harl);
void callHarlComplaint(std::string level, Harl &harl);

#endif
