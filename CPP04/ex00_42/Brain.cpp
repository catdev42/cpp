#include "Brain.hpp"
#include <iostream>

// Default constructor
Brain::Brain()
{
	std::cout << "Brain default constructor was called" << std::endl;
	return;
}

// Copy constructor
Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor was called" << std::endl;
	*this = src;
	return;
}

// Assignment operator
Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignment operator was called" << std::endl;
	if (this != &rhs)
		std::copy(rhs.ideas, rhs.ideas + MAX, ideas);
	return (*this);
}

// Destructor
Brain::~Brain()
{
	
	std::cout << "Brain destructor was called on " << name << std::endl;
	return;
}

// Getters
int Brain::getEnPoints() const { return energyPoints; }
int Brain::getHitPoints() const { return hitPoints; }
int Brain::getAttackDamage() const { return attackDamage; }
std::string Brain::getName() const { return name; }

// Setters
void Brain::setNewName(std::string _name) { name = _name; }

// Member functions
void Brain::attack(const std::string &target)
{
	if (energyPoints && hitPoints)
	{
		std::cout << "Brain " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	return;
}

void Brain::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
		return;
	hitPoints -= amount;
	std::cout << "Brain " << name << " has sustained damage of "
			  << amount << " and has " << hitPoints << " remaining " << std::endl;
	return;
}

void Brain::beRepaired(unsigned int amount)
{
	if (energyPoints && hitPoints)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "Brain " << name << " is repaired by " << amount
				  << " and now has " << hitPoints << " remaining " << std::endl;
	}
	return;
}

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Brain const &infile)
{
	o << infile.getName() << " has " << infile.getEnPoints()
	  << " energy points." << std::endl;
	o << "attack damage: " << infile.getAttackDamage() << std::endl;
	o << "hit points: " << infile.getHitPoints() << std::endl;
	return o;
}