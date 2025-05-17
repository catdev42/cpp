#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "AMateria default constructor" << std::endl;
    return;
}

AMateria::AMateria(std::string const &type) : materType(type)
{
    std::cout << "AMateria parametrized constructor" << std::endl;
    return;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "AMateria " << src.getType() << "copy constructor " << std::endl;
    return;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
    std::cout << "AMateria copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        /*Cannot reassign type*/;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor" << std::endl;
    return;
}

/********************************************/
/********************************************/
/******MEMBER FUNCTIONS******/

std::string const &AMateria::getType() const
{
    return materType;
}
void AMateria::use(ICharacter &target)
{
    std::cout << "* AMateria of type " << this->materType
              << " is used on " << target.getName()
              << ", but has no specific action by default. *" << std::endl;
}

/********************************************/
/********************************************/
/******STREAM******/

std::ostream &operator<<(std::ostream &o, const AMateria &infile)
{
    o << "Materia type, from AMateria: " << infile.getType() << std::endl;
    return o;
}

/********************************************/
/********************************************/
/******PRIVATE******/
