#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor" << std::endl;
    return;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
    std::cout << "Ice copy constructor called with "
              << src.getType() << "source" << std::endl;
    if (materType != src.getType())
        std::cout << "Types don't match - is this possible?";
    return;
}

Ice &Ice::operator=(Ice const &rhs)
{
    std::cout << "Ice copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        this->AMateria::operator=(rhs);
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor" << std::endl;
    return;
}

/********************************************/
/********************************************/
/******MEMBER FUNCTIONS******/

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
    o << "Materia type, from Ice reference object: " << infile.getType() << std::endl;
    return o;
}

/********************************************/
/********************************************/
/******PRIVATE******/
