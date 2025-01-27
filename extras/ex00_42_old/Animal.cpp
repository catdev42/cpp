#include "Animal.hpp"
#include <iostream>

// Default constructor
Animal::Animal() : default_type("Animal"), default_sound("Undetermined Animal Sound")
{
	sound = default_sound;
	type = default_type;
	std::cout << "Animal default constructor was called" << std::endl;
	return;
}

// Copy constructor
Animal::Animal(Animal const &src) : default_type("Animal"), default_sound("Undetermined Animal Sound")
{
	std::cout << "Animal copy constructor was called" << std::endl;
	type = default_type;
	sound = src.sound;
	return;
}

// Assignment operator
Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = default_type;
		sound = rhs.sound;
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
	std::cout << sound << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Animal const &infile)
{
	o << "Type: " << infile.getType()
	  << " Sound: ";
	infile.makeSound();
	return o;
}
