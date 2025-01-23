/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:47:00 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/21 14:48:06 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
	bool guardMode;

public:
	ScavTrap();
	// ScavTrap(std::string _name);
	ScavTrap(std::string _name, int _enerP = 50, int _hitP = 100, int _attDam = 20);
	ScavTrap(ScavTrap const &src);
	ScavTrap &operator=(ScavTrap const &rhs);
	~ScavTrap();

	bool getGuardMode() const;

	void attack(const std::string &target);

	void guardGate();
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &infile);

#endif
