#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character
{
private:
	/* Note: Can be array of pointers to abstract, not array of objects */
	AMateria *mater[4];

public:
	Character();
	Character(const int num);
	Character(Character const &src);
	Character &operator=(Character const &rhs);
	virtual ~Character();
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, Character &target) = 0;
};

std::ostream &operator<<(std::ostream &o, Character const &infile);

#endif
