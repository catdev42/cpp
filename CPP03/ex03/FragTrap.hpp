/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:47:00 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/25 18:21:18 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap(int _enerP = 100, int _hitP = 100, int _attDam = 30);
	FragTrap(std::string _name, int _enerP = 100, int _hitP = 100, int _attDam = 30);
	FragTrap(FragTrap const &src);
	FragTrap &operator=(FragTrap const &rhs);
	~FragTrap();


	void attack(const std::string &target);

	void highFiveGuys();
};

std::ostream &operator<<(std::ostream &o, FragTrap const &infile);

#endif
