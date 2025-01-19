/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:53:04 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/31 00:36:21 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(void);
    Weapon(std::string type);
    ~Weapon(void);

    std::string getType(void);
    void setType(std::string newType);
};

#endif
