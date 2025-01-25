#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define GREEN  "\033[32m"
#define RED  "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE  "\033[34m"
#define MAGENTA  "\033[35m"
#define CYAN  "\033[36m"
#define WHITE  "\033[37m"
#define RESET  "\033[0m"

#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

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
	
	int getEnPoints() const;
	int getHitPoints() const;
	int getAttackDamage() const;
	std::string getName() const;
void setNewName(std::string _name);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &infile);

#endif
