/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:04:19 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/02 00:51:37 by myakoven         ###   ########.fr       */
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
	harlFilter(level, harl);
}

void callHarlComplaint(std::string level, Harl &harl)
{
	std::cout << "[ " << level << " ]" << std::endl;
	harl.complain(level);
	std::cout << std::endl;
}

void harlFilter(std::string level, Harl &harl)
{
	int index = harl.getLevel(level);
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};


	switch (index)
	{
	case 0:
		callHarlComplaint(levels[index++], harl);
	case 1:
		callHarlComplaint(levels[index++], harl);
	case 2:
		callHarlComplaint(levels[index++], harl);
	case 3:
	{
		callHarlComplaint(levels[index++], harl);
		break;
	}
	default:
		std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
	}
}
