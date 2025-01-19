/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:04:19 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/19 16:52:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::string level;
	Harl harl;

	level = "debug";
	harl.complain(level);
	
	level = "info";
	harl.complain(level);
	
	level = "WARNING";
	harl.complain(level);
	
	level = "Error";
	harl.complain(level);
	
	level = "help";
	harl.complain(level);
}
