#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

// Default constructor
Dog::Dog() : AAnimal()
{
	type = "Dog";
	std::cout << "Dog default constructor was called" << std::endl;
	brain = new Brain();
	return;
}

// Copy constructor (calls assignment operator after creating the object)
Dog::Dog(Dog const &src) : AAnimal(src)
{
	std::cout << "Dog" << " copy constructor was called" << std::endl;
	brain = new Brain(*src.brain);
	type = src.type;
	return;
}

// Assignment operator
Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog" << " assignment operator was called" << std::endl;
	if (this != &rhs)
	{
		type = rhs.type;
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog" << " destructor was called" << std::endl;
	delete brain;
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

void Dog::makeSound(std::ostream &o) const
{
	o << "Woooooooof" << std::endl;
}

void Dog::giveIdea(const std::string &animalIdeas)
{
	brain->setOneIdea(animalIdeas);
}
void Dog::printIdeas() const {
	brain->printIdeas();
}
void Dog::printIdeas(std::ostream &o) const {
	brain->printIdeas(o);
}


// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile)
{
	o << "Type: " << infile.getType()
	  << "Sound : ";
	infile.makeSound(o);
	return o;
}
