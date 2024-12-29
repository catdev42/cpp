
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

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
	size_t i;

	std::string input;
	i = MAX_BOOK_LEN;
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
		if (!(ss >> i) || i < 0 || i >= this->capacity)
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
