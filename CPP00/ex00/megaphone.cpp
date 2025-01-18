/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:55:25 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/18 17:56:44 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	make_big(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	return ;
}

int	main(int argc, char **argv)
{
	int i = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		std::string str = argv[i];
		make_big(str);
		i++;
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}