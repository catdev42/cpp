#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain())
{
	std::cout << "Dog Default Constructor called" << std::endl;
}
Dog::Dog(const Dog &other) : AAnimal(other)
{
	brain = new Brain(*other.brain);
	std::cout << " AAnimal Copy constuctor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "copy assignment construstor called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

// Dog(std::string type);
void Dog::makeSound(void) const
{
	std::cout << "the " << getType() << " does le Woof" << std::endl;
}

Brain* Dog::getBrain() const{
	return brain;
}
