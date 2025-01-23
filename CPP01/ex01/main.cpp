/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:26:44 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/19 16:34:02 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{

    int i;
    int N = 20; //number of zombies to create
    Zombie *horde = zombieHorde(N, "Adam"); //call to create horde with N zombies and a name

    i = 0;
    while (i < N)
    {
        std::cout << i << ") ";
        horde[i].announce();
        i++;
    }
    delete[] horde;
}
