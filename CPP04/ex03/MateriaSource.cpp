#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        items[i] = NULL;
    }
    return;
}

MateriaSource::MateriaSource(AMateria *item)
{
    std::cout << "MateriaSource parametrized constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        items[i] = NULL;
    }
    learnMateria(item);
    return;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor" << std::endl;

    for (int i = 0; i < MAX; i++)
        if (src.items[i])
            this->items[i] = src.items[i]->clone();
    return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    std::cout << "MateriaSource copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (this->items[i])
            {
                delete this->items[i];
                this->items[i] = NULL;
            }
        }
        for (int i = 0; i < MAX; i++)
        {
            if (rhs.items[i])

                this->items[i] = rhs.items[i]->clone();
        }
    }
    return *this;
}

/* Destructor */
MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor" << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

void MateriaSource::learnMateria(AMateria *item)
{
    if (!item)
        return;
    for (int i = 0; i < MAX; i++)
        if (items[i] && items[i]->getType() == item->getType())
        {
            std::cout << "Type " << item->getType() << " already known" << std::endl;
            return;
        }
    for (int i = 0; i < MAX; i++)
    {
        if (!items[i])
        {
            items[i] = item->clone();
            std::cout << "MateriaSource learned: " << this->items[i]->getType() << " in slot " << i << std::endl;

            return;
        }
    }
    std::cout << "MateriaSource has no empty slots to learn: " << item->getType() << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < MAX; i++)
        if (items[i]->getType() == type)
            return this->items[i]->clone();
    std::cerr << "No such materia type available" << std::endl;
    return NULL;
}

// /* Stream operator overload */
// std::ostream &operator<<(std::ostream &o, const MateriaSource &infile)
// {
//     o << "No stream operator overload available"  << std::endl;
//     return o;
// }

/********************************************/
/********************************************/
/******PRIVATE******/
