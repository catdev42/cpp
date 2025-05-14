#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
	AMateria *mater[4];

public:
	MateriaSource();
	MateriaSource(const int num);
	MateriaSource(MateriaSource const &src);
	MateriaSource &operator=(MateriaSource const &rhs);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};

std::ostream &operator<<(std::ostream &o, MateriaSource const &infile);

#endif
