#include "sample3.class.hpp"
#include <iostream>

int	main(void)
{
	Sample instance;
	Sample *instancep = &instance;

	int Sample::*p = NULL;
	void (Sample::*f)(void) const;

	p = &Sample::foo;
	std::cout << "Number P: " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Number P: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Number P: " << instance.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();

	// std::cout << "Number of instances: " << Sample::getNbinst() << std::endl;
	return (0);
}