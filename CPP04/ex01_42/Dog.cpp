#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

// Default constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor was called" << std::endl;
	return;
}

// Copy constructor
Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog copy constructor was called" << std::endl;
	type = src.type;
	return;
}

// Assignment operator
Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor was called" << std::endl;
	return;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile)
{
	o << GREEN << "Type: " << infile.getType() << "Sound: ";
	infile.makeSound();
	o << RESET;
	return o;
}
