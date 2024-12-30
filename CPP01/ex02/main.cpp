/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:38:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/12/30 21:47:55 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string& strREF = str;

    std::cout << "Memory address of str:    " << &str << std::endl;
    std::cout << "Memory address of strPTR: " << strPTR << std::endl;
    std::cout << "Memory address of strREF: " << &strREF << std::endl;

    std::cout << "Value of str:    " << str << std::endl;
    std::cout << "Value of strPTR: " << *strPTR << std::endl;
    std::cout << "Value of strREF: " << strREF << std::endl;
}
