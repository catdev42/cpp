#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor was called" << std::endl;
	return;
}

// Copy constructor
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor was called" << std::endl;
	type = src.type;
	return;
}

// Assignment operator
WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor was called" << std::endl;
	return;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, WrongCat const &infile)
{
	o << GREEN << "Type: " << infile.getType() << std::endl;
	o << "Sound: ";
	infile.makeSound();
	o << RESET << std::endl;
	return o;
}
