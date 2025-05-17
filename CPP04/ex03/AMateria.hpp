#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter; // FORWARD DECLARATION (INSTEAD OF INCLUDE)

class AMateria
{
private:
	AMateria(); // can't be used because its virtual

protected:
	std::string const materType;

public:
	AMateria(std::string const &type); // parametrized
	AMateria(AMateria const &src);
	AMateria &operator=(AMateria const &rhs);
	virtual ~AMateria();

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

std::ostream &operator<<(std::ostream &o, AMateria const &infile);

#endif
