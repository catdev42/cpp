#include "sample3.class.hpp"
#include <iostream>

Sample::Sample(void) : foo(0)
{
	std::cout << "Constructor Called" << std::endl;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	return ;
}

void Sample::bar(void) const
{
	std::cout << "Bar member function called" << std::endl;
	return ;
}
