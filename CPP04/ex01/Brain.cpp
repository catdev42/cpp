#include "Brain.hpp"
#include <iostream>

// Default constructor
Brain::Brain()
{
	std::cout << "Brain default constructor was called" << std::endl;
	return;
}

// Copy constructor
Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor was called" << std::endl;
	std::copy(src.ideas, src.ideas + MAX, ideas);
	return;
}

// Assignment operator
Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignment operator was called" << std::endl;
	if (this != &rhs)
		std::copy(rhs.ideas, rhs.ideas + MAX, ideas);
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor was called" << std::endl;
	return;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Brain const &infile)
{
	o << "Brain address: " << &infile << std::endl;
	return o;
}