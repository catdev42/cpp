/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:27:38 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/31 00:54:44 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>

// private:
//     std::string _name;
//     Weapon *_weapon;

// public:

HumanB::HumanB(std::string nameVar) : _name(nameVar)
{
    return;
}

HumanB::~HumanB(void)
{
    std::cout << _name << " destructor called (HumanB)" << std::endl;
    return;
}

void HumanB::attack(void)
{
    if (_weapon)
        std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
    return;
}

void HumanB::setWeapon(Weapon& weaponREF)
{
    _weapon = &weaponREF;
    return;
}
