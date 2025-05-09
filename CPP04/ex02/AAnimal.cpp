#include "AAnimal.hpp"
#include <iostream>

// Default constructor
AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor was called" << std::endl;
	return;
}

// Copy constructor (calls assignment operator after creating the object)
AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal" << " copy constructor was called" << std::endl;
	*this = src;
	return;
}

// Assignment operator
AAnimal &AAnimal::operator=(AAnimal const &rhs)
{

	std::cout << "AAnimal" << " assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal" << " destructor was called" << std::endl;
	return;
}

// Getters
std::string AAnimal::getType() const { return type; }

// Setters

// Member functions
void AAnimal::makeSound() const
{
	std::cout << "No Sound" << std::endl;
}

void AAnimal::makeSound(std::ostream &o) const
{
	o << "No Sound" << std::endl;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, const AAnimal &infile)
{
	o << "Type: " << infile.getType()
	  << "Sound : ";
	infile.makeSound(o);
	return o;
}
