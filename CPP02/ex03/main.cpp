/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:28:47 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/25 21:51:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <iomanip>

bool bsp(const Point a, const Point b, const Point c, const Point point);

void print_point(Point a, Point b, Point c, Point point)
{
	std::cout << "The point( x= " << std::left
			  << std::setw(10) << point.getX() << std::setw(0) << "\ty= " << std::setw(10) << point.getY() << std::setw(0) << "\t) is inside the triangle\n"
			  << "\ta( x= " << std::setw(10) << a.getX() << std::setw(0) << "\ty= " << std::setw(10) << a.getY() << std::setw(0) << "\t" << ")\n"
			  << "\tb( x= " << std::setw(10) << b.getX() << std::setw(0) << "\ty= " << std::setw(10) << b.getY() << std::setw(0) << "\t" << ")\n"
			  << "\tc( x= " << std::setw(10) << c.getX() << std::setw(0) << "\ty= " << std::setw(10) << c.getY() << std::setw(0) << "\t" << ")\n"
			  << std::endl;
}

int main(void)
{
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(11, 3);

		print_point(a, b, c, point);
		// std::cout << "The point( x= " << point.getX() << "\ty= " << point.getY() << "\t) is inside the triangle\n" <<
		// "\ta( x= " << a.getX() << "\t\ty= " << a.getY() << "\t)\n" <<
		// "\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n" <<
		// "\tc( x= " << c.getX() << "\t\ty= " << c.getY() << "\t)\n" << std::endl;
		if (bsp(a, b, c, point) == true)
			std::cout << "\033[32mTRUE\033[0m" << std::endl;
		else
			std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	std::cout << "\n---------------------------------------------------------------------\n"
			  << std::endl;
	{
		Point a(-1.5f, -1.5f);
		Point b(2.5f, 2.5f);
		Point c(-1, -2);
		Point point(-1.0f, -1.5f);

		print_point(a, b, c, point);

		if (bsp(a, b, c, point) == true)
			std::cout << "\033[32mTRUE\033[0m" << std::endl;
		else
			std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	return (0);
}
