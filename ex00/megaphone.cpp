/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:55:25 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/28 05:00:15 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*make_big(char *str)
{
	int		len;
	// char	*new_str;
	int		i;

	len = std::strlen(str);
	// new_str = new char[len + 2];
	i = 0;
	while (i < len)
	{
		// new_str[i] = (char)std::toupper(static_cast<unsigned char>(str[i]));
		std::cout << (char)std::toupper(str[i]);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int i = 1;
	// char *new_str;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		// new_str = make_big(argv[i]);
		// std::cout << new_str;
		// delete[] new_str;
		make_big(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}