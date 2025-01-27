#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unknown")
{
	std::cout << "Default Constructor called" << std::endl;
}
AAnimal::AAnimal(const std::string& type) : type(type)
{
	std::cout << "Animal created with " << type << std::endl;
}
AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor called" << std::endl;
}
std::string AAnimal::getType() const
{
	return type;
}
