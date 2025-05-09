#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

// Default constructor
Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor was called" << std::endl;
	return;
}

// Copy constructor (calls assignment operator after creating the object)
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat" << " copy constructor was called" << std::endl;
	type = src.type;
	return;
}

// Assignment operator
Cat &Cat::operator=(Cat const &rhs)
{

	std::cout << "Cat" << " assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat" << " destructor was called" << std::endl;
	return;
}

// Getters
std::string Cat::getType() const { return type; }

// Setters

// Member functions
void Cat::makeSound() const
{
	std::cout << "MEOWWWWWW" << std::endl;
}

void Cat::makeSound(std::ostream &o) const
{
	o << "MEOWWWWWW" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Cat const &infile)
{
	o << "Type: " << infile.getType()
	  << "Sound : ";
	infile.makeSound(o);
	return o;
}
