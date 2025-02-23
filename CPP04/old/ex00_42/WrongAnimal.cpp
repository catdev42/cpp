#include "WrongAnimal.hpp"
#include <iostream>

// Default constructor
WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor was called" << std::endl;
	return;
}

// Copy constructor
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor was called" << std::endl;
	type = src.type;
	return;
}

// Assignment operator
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor was called" << std::endl;
	return;
}

// Getters and setters

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Undetermined WrongAnimal Sound" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, WrongAnimal const &infile)
{
	o << "Type: " << infile.getType()
	  << " Sound: ";
	infile.makeSound();
	return o;
}
