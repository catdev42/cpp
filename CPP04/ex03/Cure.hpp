#ifndef CURE_HPP
#define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
private:
	
public:
	Cure();
	Cure( Cure const & src);
	Cure &	operator=( Cure const & rhs);
	virtual ~Cure();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, Cure const &infile);

#endif
