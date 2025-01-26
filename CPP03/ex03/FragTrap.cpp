#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	energyPoints = default_energy_points;
	hitPoints = default_hit_points;
	attackDamage = default_attack_damage;
	std::cout << "FragTrap Default Constructor was called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	energyPoints = default_energy_points;
	hitPoints = default_hit_points;
	attackDamage = default_attack_damage;
	std::cout << "FragTrap Named Constructor was called with the name " << getName() << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap()
{
	std::cout << "FragTrap Copy Constructor was called" << std::endl;
	*this = src;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap assignment operator= called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor was called on " << getName() << std::endl;
	return;
}

/* PUBLIC */

void FragTrap::attack(const std::string &target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << getName() << " attacks target " << target
				  << " causing " << attackDamage << " points of damage" << std::endl;
		this->energyPoints--;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "FragTrap " << getName() << " is not able to attack "
				  << target << " due to no hit points left." << std::endl;
	}
	if (energyPoints <= 0)
	{
		std::cout << "FragTrap " << getName() << " is not able to attack "
				  << target << " due to no energy points left." << std::endl;
	}
	return;
}

void FragTrap::highFiveGuys()
{
	std::cout << BLUE << "High Fives request ACCEPTED by FragTrap " << getName() << RESET << std::endl;
	return;
}

std::ostream &operator<<(std::ostream &o, FragTrap const &infile)
{
	std::cout << GREEN << "FragTrap " << infile.getName()
			  << " has " << infile.getEnPoints() << " energy points." << std::endl;
	std::cout << "Attack Damage: " << infile.getAttackDamage() << std::endl;
	std::cout << "Hit Points: " << infile.getHitPoints() << RESET << std::endl;
	return (o);
}
