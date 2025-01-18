/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:57:39 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/17 14:19:45 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <sstream> //for stringstream

/*PRIVATE*/

void PhoneBook::updateStats()
{
	this->_updateOldest();
	this->_updateLen();
}

/* works with a copy, not by reference */
std::string PhoneBook::formatEntry(std::string entry)
{
	if (entry.length() > 10)
		entry = entry.substr(0, 9) + ".";
	return (entry);
}

size_t PhoneBook::getIndexFromUser(void)
{
	long int i;

	std::string input;
	// i = MAX_BOOK_LEN;
	while (true)
	{
		std::cout << "Please enter the contact index: ";
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
		if (!(ss >> i) || i < 0 || static_cast<size_t>(i) >= this->capacity)
		{
			std::cout << "Current entry:" << input << std::endl;
			std::cout << INDEX_ERR << (this->capacity - 1) << std::endl;
			continue ;
		}
		break ;
	}
	return (static_cast<size_t>(i));
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

/*PUBLIC */

PhoneBook::PhoneBook() : capacity(MAX_BOOK_LEN), _len(0), _oldestIndex(0)
{
	std::cout << "PhoneBook Constructor Called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook Destructor Called" << std::endl;
	return ;
}

void PhoneBook::addContact(size_t index_)
{
	book[index_] = Contact(index_);
	this->updateStats();
	return ;
}

void PhoneBook::searchBook(void)
{
	size_t	index;

	for (size_t i = 0; i < this->capacity; i += 1)
	{
		std::cout << "|";
		std::cout << std::setw(10) << formatEntry(book[i].getIndexStr()) << "|";
		std::cout << std::setw(10) << formatEntry(book[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatEntry(book[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatEntry(book[i].getNickname()) << "|";
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

size_t PhoneBook::getLen()
{
	return (this->_len);
}

size_t PhoneBook::getOldest(void)
{
	return (this->_oldestIndex);
}
