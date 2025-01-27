#ifndef ICE_H
#define ICE_H

#include "AMateria.h"
#include "ICharacter.h"

class Ice : public AMateria {
public:
    Ice();
    virtual ~Ice();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // ICE_H
