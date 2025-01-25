#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_trap")
{
	std::cout << "Default Constructor was called (name: Nameless)" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string _name) : name(_name)
{
	std::cout << "DiamondTrap Named Constructor was called with the name " << name << std::endl;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << "Copy Constructor was called. Name: " << src.getName() << std::endl;
	*this = src;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "Operator= overloader was called" << std::endl;
	if (this != &rhs)
	{
		name = rhs.name;
		energyPoints = rhs.energyPoints;
		hitPoints = rhs.hitPoints;
		attackDamage = rhs.attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor was called on " << name << std::endl;
	return;
}

/* PUBLIC MEMBER FUNCTIONS */

	void whoAmI(){
			std::cout << infile.getName() << "\033[32m" << " has " << infile.getEnPoints()
			  << " energy points." << std::endl;
	}

/* NONMEMBER */

std::ostream &operator<<(std::ostream &o, DiamondTrap const &infile)
{
	std::cout << infile.getName() << "\033[32m" << " has " << infile.getEnPoints()
			  << " energy points." << std::endl;
	std::cout << "Attack Damage: " << infile.getAttackDamage() << std::endl;
	std::cout << "Hit Points: " << infile.getHitPoints() << "\033[0m" << std::endl;
	return (o);
}
