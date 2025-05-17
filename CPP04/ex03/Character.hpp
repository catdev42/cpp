#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string &name);
	Character(Character const &src);
	Character &operator=(Character const &rhs);
	virtual ~Character();

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

private:
	enum
	{
		MAX = 4
	};
	AMateria *items[MAX];
	std::string name;
};

std::ostream &operator<<(std::ostream &o, const Character &infile);

#endif
