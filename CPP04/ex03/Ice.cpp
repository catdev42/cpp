#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor" << std::endl;
    return;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
    std::cout << "Ice copy constructor" << std::endl;
    /*TODO*/;
    return;
}

Ice &Ice::operator=(Ice const &rhs)
{
    std::cout << "Ice copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        /*TODO*/;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor" << std::endl;
    return;
}

AMateria *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/********************************************/
/********************************************/
/******STREAM******/

std::ostream &operator<<(std::ostream &o, const Ice &infile)
{
    o << std::endl;
    return o;
}

/********************************************/
/********************************************/
/******PRIVATE******/
