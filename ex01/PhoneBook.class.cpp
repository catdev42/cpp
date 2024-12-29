/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:57:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 01:59:10 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <sstream> //for stringstream

void PhoneBook::addContact(size_t index_)
{
	book[index_] = Contact(index_);
	this->updateStats();
	return ;
}

/* works with a copy, not by reference */
std::string PhoneBook::formatEntry(std::string entry)
{
	if (entry.length() > 10)
		entry = entry.substr(0, 9) + ".";
	return (entry);
}

void PhoneBook::searchBook(void)
{
	size_t	index;

	for (size_t i = 0; i < this->capacity; i += 1)
	{
		std::cout << "|";
		std::cout << std::setw(10) << formatEntry(book[i].getIndexStr()) << "|";
		std::cout << std::setw(10) << formatEntry(book[i].firstName) << "|";
		std::cout << std::setw(10) << formatEntry(book[i].lastName) << "|";
		std::cout << std::setw(10) << formatEntry(book[i].nickname) << "|";
		std::cout << std::endl;
	}
	index = this->getIndexFromUser();
	if (index == this->capacity)
	{
		std::cout << std::setw(10) << "Exiting SEARCH" << std::endl;
		return ;
	}
	book[index].printFields();
	return ;
}

size_t PhoneBook::getIndexFromUser(void)
{
	int		i;
	bool	goodInput;

	goodInput = true;
	std::string input;
	i = -1;
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof()) 
			{
				std::cin.clear();       
				std::cout << std::endl; 
				return (this->capacity);  
			}
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input, try again or write EXIT" << std::endl;
			continue ;
		}
		if (input == "EXIT")
			return (this->capacity);
		std::stringstream ss(input);
		if (!ss >> i)
		{
			std::cout << "Please enter a number from 0 to " << (this->capacity
				- 1) << std::endl;
			goodInput = false;
			i = -1;
			continue ;
		}
		if (i < 0 || i >= this->capacity)
		{
			std::cout << "Please enter a number from 0 to " << (this->capacity
				- 1) << std::endl;
			i = -1;
			continue ;
		}
		break ;
	}
	return (static_cast<size_t>(i));
}

size_t PhoneBook::getLen()
{
	return (this->_len);
}

size_t PhoneBook::getOldest(void)
{
	return (this->_oldestIndex);
}

PhoneBook::PhoneBook() : _len(0), capacity(MAX_BOOK_LEN)
{
	std::cout << "PhoneBook Constructor Called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Destructor Called" << std::endl;
	return ;
}

/*PRIVATE*/

void PhoneBook::updateStats()
{
	this->_updateOldest();
	this->_updateLen();
}

void PhoneBook::_updateOldest()
{
	if (this->_len == 8)
		_oldestIndex = (_oldestIndex + 1) % 8;
	return ;
}

void PhoneBook::_updateLen()
{
	if (this->_len < 8)
		this->_len += 1;
	return ;
}

// size_t PhoneBook::getIndexFromUser(void)
// {
// 	int	i;

// 	while (true)
// 	{
// 		if (!std::cin >> i)
// 		{
// 			std::cout << "Invalid, input must be numeric" << std::endl;
// 			std::cin.ignore(10000, '\n'); // Clear remaining input
// 			continue ;
// 		}
// 		if (i < 0 || i >= this->capacity)
// 		{
// 			std::cout << "Please enter a number from 0 to " << (this->capacity
// - 1) << std::endl;
// 			continue ;
// 		}
// 		break ;
// 	}
// 	return (i);
// }