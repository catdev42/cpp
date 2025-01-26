/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:47:00 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/26 23:17:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
private:
	bool guardMode;

protected:
	static const int default_hit_points = 100;
	static const int default_energy_points = 50;
	static const int default_attack_damage = 20;

public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(ScavTrap const &src);
	ScavTrap &operator=(ScavTrap const &rhs);
	~ScavTrap();

	bool getGuardMode() const;

	void attack(const std::string &target);
	void guardGate();
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &infile);

#endif
