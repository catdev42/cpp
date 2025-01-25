/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:44:10 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/12 15:26:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _availBits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fnum);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	void setRawBits(int const raw);
	void setValue(int const num);
	void setValue(float const num);

	int getRawBits(void) const;
	int getAvailBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &lhs, Fixed &rhs);
	static const Fixed &min(Fixed const &lhs, Fixed const &rhs);
	static Fixed &max(Fixed &lhs, Fixed &rhs);
	static const Fixed &max(Fixed const &lhs, Fixed const &rhs);

	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;

	Fixed &operator*=(int const num);
	Fixed &operator*=(Fixed const &other);

	Fixed operator/(Fixed const &other) const;

	// pre
	Fixed &operator++();
	Fixed &operator--();
	// post
	Fixed operator++(int);
	Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &o, Fixed const &infile);

Fixed operator*(Fixed const &fixObj, int const num);
Fixed operator*(int const num, Fixed const &fixObj);
// Fixed operator*(Fixed const &fixObj1, Fixed const &fixObj2);

#endif
