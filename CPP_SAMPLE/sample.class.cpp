#include "sample.class.hpp"
#include <iostream>

Sample::Sample(void)
{
	std::cout << "Constructor Called" << std::endl;
	Sample::_nbinst += 1;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	Sample::_nbinst -= 1;
	return ;
}

int Sample::getNbinst(void)
{
	return (Sample::_nbinst);
}

int Sample::_nbinst = 0;
