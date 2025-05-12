#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice
{
private:

public:
	Ice();
	Ice(const int num);
	Ice(Ice const &src);
	Ice &operator=(Ice const &rhs);
	~Ice();

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Ice const &infile);

#endif
