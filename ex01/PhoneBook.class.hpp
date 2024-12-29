/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:51:13 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 01:58:21 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
# include <string>

# define MAX_BOOK_LEN 8

class PhoneBook
{
  public:
	Contact book[MAX_BOOK_LEN];
	const size_t capacity;

	PhoneBook();
	~PhoneBook();

	void addContact(size_t index_);
	void searchBook();

	size_t getLen();
	size_t getOldest(void);

  private:
  
	void updateStats();
	size_t getIndexFromUser();
	std::string formatEntry(std::string entry);
	size_t _len;
	size_t _oldestIndex;
	
	void _updateOldest();
	void _updateLen();
};

#endif
