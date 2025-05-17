#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
private:
public:
	Ice();
	Ice(Ice const &src);
	Ice &operator=(Ice const &rhs);
	virtual ~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Ice const &infile);

#endif
