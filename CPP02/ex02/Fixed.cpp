#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default Constructor was called" << std::endl;
	return;
}

Fixed::Fixed(const int num) : _value(roundf(num * (1 << _availBits)))
{
	// std::cout << "Int Constructor was called" << _value << std::endl;
	return;
}
Fixed::Fixed(const float fnum) : _value(roundf(fnum * (1 << _availBits)))
{
	// std::cout << "Float Constructor was called" << _value << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy Constructor was called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor was called" << std::endl;
	return;
}

/* ASSIGNMENT OPERATOR */
Fixed &Fixed::operator=(Fixed const &rhs)
{
	// std::cout << "Operator overloader was called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

/* SETTERS */

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits was called" << std::endl;
	_value = raw;
	return;
}

void Fixed::setValue(int const num)
{
	// std::cout << "setValueInt was called" << std::endl;
	_value = roundf(num * (1 << _availBits));
	return;
}

void Fixed::setValue(float const num)
{
	// std::cout << "setValueInt was called" << std::endl;
	_value = roundf(num * (1 << _availBits));
	return;
}

/* GETTERS */

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits was called" << std::endl;
	return (_value);
}

float Fixed::toFloat(void) const
{
	// std::cout << "toFloat was called" << std::endl;
	return (this->_value / (float)(1 << _availBits));
}

int Fixed::toInt(void) const
{
	// std::cout << "toInt was called" << std::endl;
	return (roundf(this->_value / (1 << _availBits)));
}

/* MIN and MAX */

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs._value < rhs._value ? lhs : rhs);
}

const Fixed &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs._value < rhs._value ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs._value > rhs._value ? lhs : rhs);
}

const Fixed &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs._value > rhs._value ? lhs : rhs);
}

/*  OPERATOR OVERLOADING : Ad hoc polymorphism*/

bool Fixed::operator>(Fixed const &other) const
{
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->_value != other.getRawBits());
}

/* ARITHMETIC */

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed temp(*this);
	temp.setRawBits(this->_value + other.getRawBits());
	return (temp);
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed temp(*this);
	temp.setRawBits(this->_value - other.getRawBits());
	return (temp);
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed temp;
	int64_t multResult = (int64_t)this->_value * (int64_t)other.getRawBits();
	int result = static_cast<int>(roundf(multResult / (1 << this->_availBits)));
	temp.setRawBits(result);
	return (temp);
}

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed temp;
	int64_t multResult = (int64_t)this->_value * (1 << this->_availBits);
	int result = static_cast<int>(roundf(multResult / (int64_t)other._value));
	temp.setRawBits(result);
	return (temp);
}

/* Increment and Decrement Operators*/

// pre
Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}

// post
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}

/* NONMEMBER */
std::ostream &operator<<(std::ostream &o, Fixed const &infile)
{
	o << infile.toFloat();
	return (o);
}
