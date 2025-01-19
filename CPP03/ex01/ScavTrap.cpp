#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), guardModeActivated(false)
{
	energyPoints = 50;
	hitPoints = 100;
	attackDamage = 20;
	std::cout << "ScavTrap Default Constructor was called" << std::endl;
	return;
}

// ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
// {
// 	energyPoints = 50;
// 	hitPoints = 100;
// 	attackDamage = 20;
// 	std::cout << "ScavTrap Named Constructor was called" << name << std::endl;
// 	return;
// }

ScavTrap::ScavTrap(std::string _name, int _enerP, int _hitP, int _attDam) : ClapTrap(_name), guardModeActivated(false)
{
	energyPoints = _enerP;
	hitPoints = _hitP;
	attackDamage = _attDam;
	std::cout << "ScavTrap Named Constructor was called" << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	std::cout << "ScavTrap Copy Constructor was called" << std::endl;
	*this = src;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap  Operator= overloader was called" << std::endl;
	name = rhs.name;
	energyPoints = rhs.energyPoints;
	hitPoints = rhs.hitPoints;
	attackDamage = rhs.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor was called on " << name << std::endl;
	return;
}

/* PUBLIC MEMBER FUNCTIONS */

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << name << " attacks target " << target
				  << " causing " << attackDamage << " points of damage" << std::endl;
		this->energyPoints--;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is not able to attack "
				  << target << " due to no hit points left." << std::endl;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is not able to attack "
				  << target << " due to no energy points left." << std::endl;
	}
	return;
}

void ScavTrap::guardGate()
{
	guardModeActivated = true;
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	return;
}
