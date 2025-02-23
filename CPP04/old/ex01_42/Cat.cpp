#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor was called" << std::endl;
	return;
}

// Copy constructor
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor was called" << std::endl;
	type = src.type;
	return;
}

// Assignment operator
Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor was called" << std::endl;
	return;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Cat const &infile)
{
	o << GREEN << "Type: " << infile.getType() << std::endl;
	o << "Sound: ";
	infile.makeSound();
	o << RESET << std::endl;
	return o;
}
