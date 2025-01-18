/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:47:00 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/13 09:02:46 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(ScavTrap const &src);
	ScavTrap &operator=(ScavTrap const &rhs);
	~ScavTrap();

	void attack(const std::string &target);

    void guardGate();
};