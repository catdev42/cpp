#include "AMateria.h"

AMateria::AMateria(const std::string& type) : _type(type) {
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

AMateria::~AMateria() {
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

const std::string& AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target; // Prevent unused parameter warning
}