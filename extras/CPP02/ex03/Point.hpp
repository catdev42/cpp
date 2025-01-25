/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:29:14 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/12 15:35:54 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const int num);
	Point(const float fnum);
	Point(const int numX, const int numY);
	Point(const float numX, const float numY);
	Point(Point const &src);
	~Point();

	Point &operator=(Point const &rhs);

	// float getX() const;
	// float getY() const;

	const Fixed &getX() const;
	const Fixed &getY() const;
	
	// float Point::getX();

	// void setRawBits(int const raw);
	// void setValue(int const num);
	// void setValue(float const num);

	// int getRawBits(void) const;
	// float toFloat(void) const;
	// int toInt(void) const;

	// static Point &min(Point &lhs, Point &rhs);
	// static const Point &min(Point const &lhs, Point const &rhs);
	// static Point &max(Point &lhs, Point &rhs);
	// static const Point &max(Point const &lhs, Point const &rhs);

	// bool operator>(Point const &other) const;
	// bool operator<(Point const &other) const;
	// bool operator>=(Point const &other) const;
	// bool operator<=(Point const &other) const;
	// bool operator==(Point const &other) const;
	// bool operator!=(Point const &other) const;

	// Point operator+(Point const &other) const;
	// Point operator-(Point const &other) const;
	// Point operator*(Point const &other) const;
	// Point operator/(Point const &other) const;

	// // pre
	// Point &operator++();
	// Point &operator--();
	// // post
	// Point operator++(int);
	// Point operator--(int);
};

std::ostream &operator<<(std::ostream &o, Point const &infile);

#endif
