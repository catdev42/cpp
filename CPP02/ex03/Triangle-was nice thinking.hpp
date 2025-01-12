#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

class Triangle
{
private:
	Point a;
	Point b;
	Point c;

public:
	Triangle();
	Triangle(float aX, float aY, float bX, float bY, float cX, float cY);
	Triangle(Point &_a, Point &_b, Point &_c);
	Triangle(Triangle const &src);
	~Triangle();

	Triangle &operator=(Triangle const &rhs) const;

	// type getFoo(void) const
};

std::ostream &operator<<(std::ostream &o, Triangle const &infile);

#endif
