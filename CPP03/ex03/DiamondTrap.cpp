/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:29:55 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/26 23:25:12 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("Nameless_clap_name"), ScavTrap(), FragTrap()
{
	name = "Nameless";
	energyPoints = default_energy_points;
	hitPoints = default_hit_points;
	attackDamage = default_attack_damage;
	std::cout << "Default Constructor was called (name: Nameless)" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name)
{
	name = _name;
	energyPoints = default_energy_points;
	hitPoints = default_hit_points;
	attackDamage = default_attack_damage;
	std::cout << "DiamondTrap Named Constructor was called with the name "
			  << name << std::endl;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
	: ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "Copy Constructor was called. Name: " << src.getName()
			  << std::endl;
	ClapTrap::setNewName(src.name + "_clap_name");
	*this = src;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap assignment operator= called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		ClapTrap::setNewName(rhs.name + "_clap_name");
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		name = rhs.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor was called on " << name << std::endl;
	return;
}

/* GET and SET */

std::string DiamondTrap::getName() const { return (name); }

void DiamondTrap::setNewName(std::string _name) { name = _name; }

/* PUBLIC MEMBER FUNCTIONS */

void DiamondTrap::whoAmI()
{
	std::cout << YELLOW << getName() << " is my Diamond name, "
			  << "but part of me is still " << ClapTrap::getName()
			  << ". I have " << getEnPoints() << " energy points." << RESET
			  << std::endl;
}

/* NONMEMBER */

std::ostream &operator<<(std::ostream &o, DiamondTrap const &infile)
{
	std::cout << GREEN << infile.getName() << " has " << infile.getEnPoints()
			  << " energy points." << std::endl;
	std::cout << "Attack Damage: " << infile.getAttackDamage() << std::endl;
	std::cout << "Hit Points: " << infile.getHitPoints() << std::endl;
	std::cout << "GuardMode: " << infile.getGuardMode() << RESET << std::endl;
	return (o);
}
