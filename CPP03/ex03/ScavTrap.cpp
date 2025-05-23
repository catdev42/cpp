#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), guardMode(false)
{
	energyPoints = default_energy_points;
	hitPoints = default_hit_points;
	attackDamage = default_attack_damage;
	std::cout << "ScavTrap Default Constructor was called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name), guardMode(false)
{
	energyPoints = default_energy_points;
	hitPoints = default_hit_points;
	attackDamage = default_attack_damage;
	std::cout << "ScavTrap Named Constructor was called with the name " << getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	std::cout << "ScavTrap Copy Constructor was called" << std::endl;
	*this = src;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap assignment operator= called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		guardMode = rhs.guardMode;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor was called on " << getName() << std::endl;
	return;
}

/* GETTERS */
bool ScavTrap::getGuardMode() const
{
	return (guardMode);
}

/* PUBLIC MEMBER FUNCTIONS */

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << getName() << " attacks target " << target
				  << " causing " << attackDamage << " points of damage" << std::endl;
		this->energyPoints--;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is not able to attack "
				  << target << " due to no hit points left." << std::endl;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << getName() << " is not able to attack "
				  << target << " due to no energy points left." << std::endl;
	}
	return;
}

void ScavTrap::guardGate()
{
	guardMode = true;
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	return;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &infile)
{
	std::cout << GREEN << "ScavTrap " << infile.getName()
			  << " has " << infile.getEnPoints() << " energy points." << std::endl;
	std::cout << "Attack Damage: " << infile.getAttackDamage() << std::endl;
	std::cout << "Hit Points: " << infile.getHitPoints() << std::endl;
	std::cout << "Guard Mode: " << infile.getGuardMode() << RESET << std::endl;
	return (o);
}
