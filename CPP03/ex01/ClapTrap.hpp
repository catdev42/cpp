#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int energyPoints;
	int hitPoints;
	int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rhs);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream &operator<c<(std::ostream &o, ClapTrap const &infile);

#endif
