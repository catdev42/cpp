#ifndef CURE_H
#define CURE_H

#include "AMateria.h"
#include "ICharacter.h"

class Cure : public AMateria {
public:
    Cure();
    virtual ~Cure();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // CURE_H
