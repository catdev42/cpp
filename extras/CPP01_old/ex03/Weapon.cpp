/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:35:11 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/31 00:51:40 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// private:
//     std::string _type;

// public:
Weapon::Weapon(void)
{
    std::cout << "Weapon Initialized" << std::endl;
    return;
}

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Weapon " << _type << " created" << std::endl;
    return;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon Destroyed" << std::endl;
    return;
}

std::string Weapon::getType(void)
{
    return _type;
}

void Weapon::setType(std::string newType)
{
    _type = newType;
    return;
}
