#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
	static const int default_hit_points = FragTrap::default_hit_points;
	static const int default_energy_points = ScavTrap::default_energy_points;
	static const int default_attack_damage = FragTrap::default_attack_damage;
	
public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(DiamondTrap const &src);
	DiamondTrap &operator=(DiamondTrap const &rhs);
	~DiamondTrap();

	std::string getName() const;
	void setNewName(std::string _name);

	using ScavTrap::attack;
	void whoAmI();
};

std::ostream &operator<<(std::ostream &o, DiamondTrap const &infile);

#endif
