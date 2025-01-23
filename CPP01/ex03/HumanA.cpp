#include "HumanA.hpp"
#include <iostream>
#include <string>

// private:
//     std::string _name;
//     Weapon& _weapon;

// public:

HumanA::HumanA(std::string nameVar, Weapon &weaponRef)
    : _name(nameVar), _weapon(weaponRef)
{
    return;
}

HumanA::~HumanA()
{
    std::cout << _name << " destructor called (HumanA)" << std::endl;
    return;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
