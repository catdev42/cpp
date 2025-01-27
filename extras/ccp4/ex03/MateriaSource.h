#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"
#include "AMateria.h"

#include <string>
#include <iostream>

class MateriaSource : public IMateriaSource {
private:
    AMateria* _materiaLearned[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_H
