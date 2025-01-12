/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:28:28 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/12 15:41:40 by myakoven         ###   ########.fr       */
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

// float Point::getX() const
// {
// 	float actualXValue = x.toFloat();
// 	return (actualXValue);
// }

// float Point::getY() const
// {
// 	float actualYValue = y.toFloat();
// 	return (actualYValue);
// }

/*
find the areas of triangles:
a, b, point ; b, c, point; c, a, point

add the areas together and compare to are of a, b, c

To get the areas, you have to get length between:
point a & b,  b&c, a & c, a&point, b & point, c & point
float lenAB = (a.x - b.x) * (a.x - b.x) +



*/

// const Fixed &Point::getX() const
// {
// 	return (x);
// }
// const Fixed &Point::getY() const
// {
// 	return (y);
// }
