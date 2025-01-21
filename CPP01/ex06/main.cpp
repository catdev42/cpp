/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:04:19 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/21 14:24:44 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string level;
	Harl harl;

	if (argc != 2)
	{
		std::cout << "[ Add a complaint parameter: DEBUG, INFO, WARNING, ERROR ]" << std::endl;
		return 1;
	}
	level = argv[1];
	harl.harlFilter(level, harl);
}
