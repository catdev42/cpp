#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "Floor.hpp"
#include <iostream>

Character::Character() : name("no name")
{
    std::cout << "Character default constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
        this->items[i] = NULL;
    return;
}
Character::Character(std::string const &newChar) : name(newChar)
{
    std::cout << "Character parametrized (name) constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
        this->items[i] = NULL;
    return;
}

Character::Character(Character const &src) : name(src.name)
{
    std::cout << "Character copy constructor" << std::endl;
    for (int i = 0; i < MAX; i++)
        if (items[i])
            this->items[i] = src.items[i]->clone();
    return;
}

Character &Character::operator=(Character const &rhs)
{
    std::cout << "Character copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        this->name = rhs.name;
        for (int i = 0; i < MAX; i++)
            if (this->items[i])
            {
                delete this->items[i];
                this->items[i] = NULL;
            }
        for (int i = 0; i < MAX; i++)
            if (rhs.items[i])
                this->items[i] = rhs.items[i]->clone();
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < MAX; i++)
        if (this->items[i])
            delete this->items[i];
    return;
}

/********************************************/
/********************************************/
/******MEMBER FUNCTIONS******/

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < MAX; i++)
        if (this->items[i] == NULL)
        {
            this->items[i] = m;
            std::cout << this->name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    std::cout << this->name << "'s inventory is full. Cannot equip " << m->getType() << "." << std::endl;
}
void Character::unequip(int idx)
{
    if (idx > 0 && idx < MAX && items[idx])
    {
        Floor::getInstance().addToFloor(items[idx]);
        items[idx] = NULL;
        return;
    }
    std::cerr << name << ": invalid item index to unequip" << std::endl;
}
void Character::use(int idx, ICharacter &target)
{

    if (idx > 0 && idx < MAX && items[idx])
    {
        items[idx]->use(target);
    }
    std::cerr << name << ": invalid item index to use" << std::endl;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const ICharacter &infile)
{
    o << "Hello, my name is " << infile.getName() << std::endl;
    return o;
}

/********************************************/
/********************************************/
/******PRIVATE******/
