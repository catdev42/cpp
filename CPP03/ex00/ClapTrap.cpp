#include "ClapTrap.hpp"

#include <iostream>
#include <iomanip>

ClapTrap::ClapTrap() : name("Nameless"), energyPoints(10), hitPoints(10), attackDamage(0)
{
	std::cout << "Default Constructor was called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), energyPoints(10), hitPoints(10), attackDamage(0)
{
	std::cout << "Named Constructor was called" << name << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy Constructor was called" << std::endl;
	*this = src;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Operator= overloader was called" << std::endl;
	name = rhs.name;
	energyPoints = rhs.energyPoints;
	hitPoints = rhs.hitPoints;
	attackDamage = rhs.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor was called on " << name << std::endl;
	return;
}

/* GETTERS */

int ClapTrap::getEnPoints() const { return (energyPoints); }
int ClapTrap::getHitPoints() const { return (hitPoints); }
int ClapTrap::getAttackDamage() const { return (attackDamage); }
std::string ClapTrap::getName() const { return (name); }

/* PUBLIC MEMBER FUNCTIONS */

void ClapTrap::attack(const std::string &target)
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
		std::cout << "ClapTrap " << name << " is not able to attack "
				  << target << " due to no hit points left." << std::endl;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is not able to attack "
				  << target << " due to no energy points left." << std::endl;
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int amountUsed = amount;
	while (hitPoints > 0 && amountUsed > 0)
	{
		hitPoints--;
		amountUsed--;
	}
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead after an attack of " << amount << std::endl;
	else
		std::cout << "ClapTrap " << name << " has sustained damage of "
				  << amount << " and has " << hitPoints << " remaining " << std::endl;
	return;
}

// atacking and repairing cost 1 energy point each
// cant do attack without hit points or do anythign without energy points
void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints)
	{
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount
				  << " and now has " << hitPoints << " remaining " << std::endl;
	}
	return;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &infile)
{
	std::cout << infile.getName() << "\033[32m]" << " has " << infile.getEnPoints()
			  << " energy points." << std::endl;
	std::cout << "Attack Damage: " << infile.getAttackDamage() << std::endl;
	std::cout << "Hit Points: " << infile.getHitPoints() << std::endl;
	return (o);
}
