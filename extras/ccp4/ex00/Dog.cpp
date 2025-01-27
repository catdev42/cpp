#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << " Animal Copy constuctor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "copt assignment construstor called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// Dog(std::string type);
void Dog::makeSound(void) const
{
	std::cout << "the " << getType() << " does le Woof" << std::endl;
}
