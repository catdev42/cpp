/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:44:16 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/29 01:43:32 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact
{
  public:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	Contact(void);
	Contact(size_t index_input);
	~Contact(void);

	void printFields(void) const;
	std::string getIndexStr(void);

  private:
	size_t _index;

	void getUserInput(const std::string &prompt, std::string &field);
};

#endif
