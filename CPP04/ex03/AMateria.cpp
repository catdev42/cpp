#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
private:
	// ex: int _foo
protected:
	std::string const type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	AMateria &operator=(AMateria const &rhs);
	virtual ~AMateria();

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, AMateria const &infile);

#endif
