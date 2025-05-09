#include "Animal.hpp"
#include <iostream>

// Default constructor
Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor was called" << std::endl;
	return;
}

// Copy constructor (calls assignment operator after creating the object)
Animal::Animal(Animal const &src)
{
	std::cout << "Animal" << " copy constructor was called" << std::endl;
	*this = src;
	return;
}

// Assignment operator
Animal &Animal::operator=(Animal const &rhs)
{

	std::cout << "Animal" << " assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal" << " destructor was called" << std::endl;
	return;
}

// Getters
std::string Animal::getType() const { return type; }

// Setters

// Member functions
void Animal::makeSound() const
{
	std::cout << "No Sound" << std::endl;
}

void Animal::makeSound(std::ostream &o) const
{
	o << "No Sound" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, const Animal &infile)
{
	o << "Type: " << infile.getType()
	  << "Sound : ";
	infile.makeSound(o);
	return o;
}
