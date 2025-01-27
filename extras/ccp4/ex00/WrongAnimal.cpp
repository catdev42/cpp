#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Wrong animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Wrong animal paramterised constructor called." << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "Wrong animal goes woot woo" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
