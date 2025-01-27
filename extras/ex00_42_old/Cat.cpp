#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat() : Animal(), default_type("Cat"), default_sound("Meow")
{
	sound = default_sound;
	type = default_type;
	std::cout << "Cat default constructor was called" << std::endl;
	return;
}

// Copy constructor
Cat::Cat(Cat const &src) : Animal(src), default_type("Cat"), default_sound("Meow")
{
	std::cout << "Cat copy constructor was called" << std::endl;
	type = default_type;
	sound = src.sound;
	return;
}

// Assignment operator
Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = default_type;
		sound = rhs.sound;
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor was called" << std::endl;
	return;
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
