#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

// Default constructor
Dog::Dog() : Animal(), default_type("Dog"), default_sound("Woof")
{
	sound = default_sound;
	type = default_type;
	std::cout << "Dog default constructor was called" << std::endl;
	return;
}

// Copy constructor
Dog::Dog(Dog const &src) : Animal(src), default_type("Dog"), default_sound("Woof")
{
	std::cout << "Dog copy constructor was called" << std::endl;
	type = src.type;
	sound = src.sound;
	return;
}

// Assignment operator
Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
		sound = rhs.sound;
	}
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor was called" << std::endl;
	return;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile)
{
	o << GREEN << "Type: " << infile.getType() << "Sound: ";
	infile.makeSound(); 
	o << RESET << std::endl;
	return o;
}
