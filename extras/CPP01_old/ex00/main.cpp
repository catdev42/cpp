/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:26:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/30 21:01:47 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zptr;

    zptr = newZombie("Adam");
    randomChump("John");
    std::cout << "We are back in main" << std::endl;

    delete zptr;
    return (0);
}
