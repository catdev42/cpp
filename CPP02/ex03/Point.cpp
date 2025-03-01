/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:28:28 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/25 21:33:55 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

Point::Point() : x(0), y(0)
{
	return;
}

Point::Point(const int num) : x(num), y(num)
{
	return;
}

Point::Point(const float num) : x(num), y(num)
{
	return;
}

Point::Point(const int numX, const int numY) : x(numX), y(numY)
{
	return;
}

Point::Point(const float numX, const float numY) : x(numX), y(numY)
{
	return;
}
Point::Point(Point const &src) : x(src.x.toFloat()), y(src.y.toFloat())
{
	return;
}
Point::~Point()
{
	return;
}

/* ASSIGNMENT OPERATOR */
Point &Point::operator=(Point const &rhs)
{
	std::cout << "The coordinated are const values, assignment not possible to ";
	std::cout << rhs << " from " << *this;
	std::cout << std::endl;
	return (*this);
}

const Fixed &Point::getX() const
{
	return (x);
}
const Fixed &Point::getY() const
{
	return (y);
}

/* NONMEMBER */
std::ostream &operator<<(std::ostream &o, Point const &infile)
{
	o << "X: " << infile.getX().toFloat() << ", Y: "<< infile.getY().toFloat();
	return (o);
}
