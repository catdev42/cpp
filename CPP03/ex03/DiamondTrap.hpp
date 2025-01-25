#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;

public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(DiamondTrap const &src);
	DiamondTrap &operator=(DiamondTrap const &rhs);
	~DiamondTrap();

	// void attack(const std::string &target);
	using ScavTrap::attack;
	void whoAmI();
};

std::ostream &operator<<(std::ostream &o, DiamondTrap const &infile);

#endif