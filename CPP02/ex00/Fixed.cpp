#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default Constructor was called" << std::endl;
	return;
}

/*Copy Constructor*/
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy Constructor was called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor was called" << std::endl;
	return;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Operator overloader was called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits was called" << std::endl;
	_value = raw;
	return;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits was called" << std::endl;
	return (_value);
}

std::ostream &operator<<(std::ostream &o, Fixed const &infile)
{
	o << infile.getRawBits();
	return (o);
}
