#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

class ICharacter;

class AMateria
{
  protected:
	std::string _type;

  public:
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &other);

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif // AMATERIA_H
