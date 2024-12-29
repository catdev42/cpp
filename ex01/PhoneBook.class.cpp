/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:57:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 02:43:58 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <sstream> //for stringstream

PhoneBook::PhoneBook() : _len(0), capacity(MAX_BOOK_LEN), _oldestIndex(0)
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
