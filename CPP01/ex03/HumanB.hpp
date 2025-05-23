#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(std::string nameVar);
    ~HumanB(void);
    void attack(void);
    void setWeapon(Weapon& weaponREF);
};

#endif
