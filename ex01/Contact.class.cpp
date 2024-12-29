/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:55:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 01:43:14 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>
#include <string>
#include <sstream>

Contact::Contact(void) : _index(0)
{
	std::cout << "Contact Constructor Called" << std::endl;
	return ;
}

Contact::Contact(size_t index_input) : _index(index_input)
{
	getUserInput("Enter the First Name: ", firstName);
	getUserInput("Enter the Last Name: ", lastName);
	getUserInput("Enter the Nickname: ", nickname);
	getUserInput("Enter the Phone Number: ", phoneNumber);
	getUserInput("Enter the Darkest Secret: ", darkestSecret);
	return ;
}

Contact::~Contact()
{
	std::cout << "Destructor is called" << std::endl;
	return ;
}

std::string Contact::getIndexStr(void)
{
	std::stringstream ss;
	ss << this->_index;
	return (ss.str());
}

void Contact::getUserInput(const std::string &prompt, std::string &field)
{
	std::cout << prompt;
	std::getline(std::cin, field);
	std::cout << "You entered: " + field << std::endl;
	return ;
}

void Contact::printFields() const
{
	std::cout << "First Name: " + this->firstName << std::endl;
	std::cout << "Last Name: " + this->lastName << std::endl;
	std::cout << "Nickame: " + this->nickname << std::endl;
	std::cout << "Phone Number: " + this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " + this->darkestSecret << std::endl;
	return ;
}
