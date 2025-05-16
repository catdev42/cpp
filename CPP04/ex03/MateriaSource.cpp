#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        mater[i] = NULL;
        types[i] = "";
    }
    return;
}

MateriaSource::MateriaSource(AMateria *item)
{
    std::cout << "MateriaSource parametrized constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        mater[i] = NULL;
        types[i] = "";
    }
    learnMateria(item);
    return;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor" << std::endl;
    /*TODO*/;
    return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << "MateriaSource copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        /*TODO*/;
    }
    return *this;
}

/* Destructor */
MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor" << std::endl;
    return;
}

void MateriaSource::learnMateria(AMateria *item)
{
    for (int i; i < MAX; i++)
    {
    }
    AMateria *nItem = item->clone();
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
}

/* Stream operator overload */
std::ostream &operator<<(std::ostream &o, const MateriaSource &infile)
{
    o << std::endl;
    return o;
}

/********************************************/
/********************************************/
/******PRIVATE******/
