#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
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

	void getEnPoints() const;
	void getHitPoints() const;
	void getAttackDamage() const;	

	void attack(const std::string &target);
	// opponent gets attackdamage, attacker looses hit points
	// attack uses opponenets take damage function
	void takeDamage(unsigned int amount);
	// atacking and repairing cost 1 energy point each
	// cant do attack without hit points or do anythign without energy points
	void beRepaired(unsigned int amount);
	// type getFoo(void) const

};

std::ostream &operator<<(std::ostream &o, ClapTrap const &infile);

#endif
