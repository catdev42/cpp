/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:05:02 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/31 22:11:45 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

void replaceText(std::ifstream &infile, std::ofstream &outfile, std::string str1, std::string str2);

#endif
