#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor" << std::endl;
    return;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
    std::cout << "Cure copy constructor" << std::endl;
    return;
}

Cure &Cure::operator=(Cure const &rhs)
{
    std::cout << "Cure copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        this->AMateria::operator=(rhs);
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor" << std::endl;
    return;
}

AMateria *Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter &target) {
    std::cout<< "* heals "<< target.getName() << "'s wounds *" <<std::endl;
}

/********************************************/
/********************************************/
/******STREAM******/

std::ostream &operator<<(std::ostream &o, const Cure &infile)
{
    o << std::endl;
    return o;
}

/********************************************/
/********************************************/
/******PRIVATE******/
