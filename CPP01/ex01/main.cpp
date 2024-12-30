/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:26:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/30 21:29:11 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{

    Zombie *hordePtr;
    int i;
    int N;
    
    N = 20;
    hordePtr = zombieHorde(N, "Adam");
    i = 0;
    while (i < N)
    {
        std::cout << i << ") ";
        hordePtr[i].announce();
        i++;
    }
    delete [] hordePtr;
}
