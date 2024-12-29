/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 23:07:37 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 02:33:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	phoneBook;
	bool		toExit;
	int			index;

	std::string input;
	toExit = false;
	while (!toExit)
	{
        std::cout << "Select an action ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
        std::cout << std::endl;
		if (input == "EXIT")
			toExit = true;
		else if (input == "ADD")
		{
			if (phoneBook.getLen() == phoneBook.capacity)
				index = phoneBook.getOldest();
			else
				index = phoneBook.getLen();
			phoneBook.addContact(index);
		}
		else if (input == "SEARCH")
			phoneBook.searchBook();
		else
			std::cout << ERROR_MESSAGE << std::endl;
	}
	return ;
}
