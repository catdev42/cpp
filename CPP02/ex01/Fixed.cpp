#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default Constructor was called" << std::endl;
	return;
}

Fixed::Fixed(const int num) : _value(roundf(num * (1 << _availBits)))
{
	std::cout << "Int Constructor was called" << _value << std::endl;
	return;
}

Fixed::Fixed(const float fnum) : _value(roundf(fnum * (1 << _availBits)))
{
	std::cout << "Float Constructor was called" << _value << std::endl;
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

float Fixed::toFloat(void) const
{
	return (this->_value / (float)(1 << _availBits));
}
int Fixed::toInt(void) const
{
	return (roundf(this->_value / (1 << _availBits)));
}

std::ostream &operator<<(std::ostream &o, Fixed const &infile)
{
	o << infile.toFloat();
	return (o);
}

/*
static float ft_pow(float base, int exp)
{
	float result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}
*/
