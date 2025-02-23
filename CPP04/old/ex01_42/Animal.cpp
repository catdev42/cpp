#include "Animal.hpp"
#include <iostream>

// Default constructor
Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal default constructor was called" << std::endl;
	return;
}

// Copy constructor
Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor was called" << std::endl;
	type = src.type;
	return;
}

// Assignment operator
Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor was called" << std::endl;
	return;
}

// Getters and setters

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Undetermined Animal Sound" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Animal const &infile)
{
	o << "Type: " << infile.getType()
	  << " Sound: ";
	infile.makeSound();
	return o;
}
