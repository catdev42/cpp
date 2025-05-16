#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	enum {
		MAX = 4
	};
	AMateria *mater[MAX];
	std::string types[MAX];

public:
	MateriaSource();
	MateriaSource(AMateria *item);
	MateriaSource(MateriaSource const &src);
	MateriaSource &operator=(MateriaSource const &rhs);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria *item);
	virtual AMateria *createMateria(std::string const &type);
};

std::ostream &operator<<(std::ostream &o, MateriaSource const &infile);

#endif
