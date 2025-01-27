#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain())
{
	std::cout << "Cat Default Constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : AAnimal(other)
{
	brain = new Brain(*other.brain);
	std::cout << " AAnimal Copy constuctor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment construstor called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

// Cat(std::string type);
void Cat::makeSound(void) const
{
	std::cout << "the " << getType() << " does le meow" << std::endl;
}


Brain* Cat::getBrain() const{
	return brain;
}
