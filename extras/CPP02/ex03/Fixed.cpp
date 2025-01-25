/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:28:41 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/12 15:26:33 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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

int Fixed::getAvailBits(void) const
{
	// std::cout << "getAvailBits was called" << std::endl;
	return (this->_availBits);
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
	int result = static_cast<int>(std::roundf(multResult / (1 << this->_availBits)));
	temp.setRawBits(result);
	return (temp);
}

Fixed &Fixed::operator*=(int const num)
{
	this->_value = static_cast<int>(std::roundf(static_cast<float>(this->_value) * num));
	return (*this);
}

Fixed &Fixed::operator*=(Fixed const &other)
{
	int64_t multResult = (int64_t)this->_value * (int64_t)other.getRawBits();
	this->_value = static_cast<int>(std::roundf(multResult / (1 << this->_availBits)));
	return (*this);
}

// Fixed Fixed::operator*(int const num) const
// {
// 	Fixed temp;
// 	temp.setRawBits(this->getRawBits() * num);
// 	return (temp);
// }

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed temp;
	int64_t multResult = (int64_t)this->_value * (1 << this->_availBits);
	int result = static_cast<int>(std::roundf(multResult / (int64_t)other._value));
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

Fixed operator*(Fixed const &fixObj, int const num)
{
		return (fixObj * Fixed(num));
}

Fixed operator*(int const num, Fixed const &fixObj)
{
	return (fixObj * Fixed(num));
}

// Fixed operator*(Fixed const &fixObj1, Fixed const &fixObj2)
// {
// 	Fixed temp;
// 	int64_t multResult = (int64_t)fixObj1.getRawBits() * (int64_t)fixObj2.getRawBits();
// 	int result = static_cast<int>(std::roundf(multResult / (1 << fixObj1.getAvailBits())));
// 	temp.setRawBits(result);
// 	return (temp);
// }
