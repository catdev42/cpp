#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
    std::string _name;
    Weapon &_weapon;

public:
    HumanA(std::string nameVar, Weapon &weaponRef);
    ~HumanA(void);
    void attack(void);
};

#endif
