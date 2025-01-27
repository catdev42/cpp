#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default Constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << " Animal Copy constuctor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "copt assignment construstor called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

// Cat(std::string type);
void Cat::makeSound(void) const
{
	std::cout << "the " << getType() << " does le meow" << std::endl;
}
