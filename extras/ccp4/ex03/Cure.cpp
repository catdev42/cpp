#include "Cure.h"
#include "ICharacter.h"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
