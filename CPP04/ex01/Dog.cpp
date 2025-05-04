#include "Dog.hpp"
#include "Animal.hpp"

#include <iostream>
#include <string>

// Default constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor was called" << std::endl;
	return;
}


// Copy constructor (calls assignment operator after creating the object)
Dog::Dog(Dog const &src)
{
	std::cout << "Dog" << " copy constructor was called" << std::endl;
	*this = src;
	return;
}

// Assignment operator
Dog &Dog::operator=(Dog const &rhs)
{

	std::cout << "Dog" << " assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog" << " destructor was called" << std::endl;
	return;
}

// Getters
std::string Dog::getType() const { return type; }

// Setters

// Member functions
void Dog::makeSound() const
{
	std::cout << "Woooooooof" << std::endl;
}

void Dog::makeSoundToStream(std::ostream &o) const
{
	o << "Woooooooof" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile)
{
	o << "Type: " << infile.getType()
	  << "Sound : ";
	infile.makeSoundToStream(o);
	return o;
}
