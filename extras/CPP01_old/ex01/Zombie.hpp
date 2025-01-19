/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:04:47 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/30 21:19:52 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie();
	Zombie(std::string name_given);
	~Zombie();

	void setName(std::string name);
	void announce(void);
};

Zombie*    zombieHorde( int N, std::string name );

#endif
