/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:44:16 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 02:39:36 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{
  public:
	
	Contact(void);
	Contact(size_t index_input);
	~Contact(void);

	void printFields(void) const;
	std::string getIndexStr(void);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	
	

  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	size_t _index;

	void getUserInput(const std::string &prompt, std::string &field);
};

#endif
