/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:45:28 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/12 15:32:22 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2

/*
IT WOULD BE NICE IF THE MATH WAS DONE ON FIXED POINT NUMBERS!!! Otherwise whats the point, right now its like we are just storing the ints and working with flaots anyway, its dumb...
*/

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area;

	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	if (area.getRawBits() < 0)
		area = area * -1;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed whole;
	Fixed tA, tB, tC;
	Fixed sumOfTriangles;
	

	whole = area(a, b, c);
	tA = area(a, b, point);
	tB = area(b, c, point);
	tC = area(c, a, point);
	
	sumOfTriangles = tA + tB + tC;
	
	return (sumOfTriangles <= whole);
}
