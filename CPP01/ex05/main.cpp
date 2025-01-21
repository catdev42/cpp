/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:04:19 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/21 14:37:03 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int i = 1;
	std::string level;
	Harl harl;

	if (argc < 2)
		std::cout << "Please enter your comlaint level: DEBUG, INTO, WARNING or ERROR" << std::endl;
	else
		while (argv[i])
		{
			harl.complain(argv[i++]);
			if (argv[i])
				std::cout << std::endl;
		}
	return 0;
}
