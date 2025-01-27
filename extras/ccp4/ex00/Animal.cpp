#include "Animal.hpp"

Animal::Animal() : type("Generic Animal")
{
	std::cout << "Default Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}
void Animal::makeSound() const
{
	std::cout << type << " does le Generic animal sound!" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
