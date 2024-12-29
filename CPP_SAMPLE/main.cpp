#include "sample.class.hpp"
#include <iostream>

int	main(void)
{
	Sample s;
	std::cout << "Number of instances: " << Sample::getNbinst() << std::endl;

	// createSample();
	Sample s2;


	std::cout << "Number of instances: " << Sample::getNbinst() << std::endl;
	return (0);
}