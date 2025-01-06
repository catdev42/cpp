/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:44:10 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/06 22:22:18 by myakoven         ###   ########.fr       */
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
	Fixed(Fixed const &src);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	void setRawBits(int const raw);
	int getRawBits(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &infile);

#endif
