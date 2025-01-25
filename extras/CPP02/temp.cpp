/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 01:39:13 by myakoven          #+#    #+#             */
/*   Updated: 2025/01/03 03:55:11 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

// countpp1.cpp
// increment counter variable with ++ operator
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter
{
private:
	unsigned int count; // count
public:
	Counter() : count(0) // constructor
	{
	}
	unsigned int get_count() // return count
	{
		return count;
	}
	void operator++() // increment (prefix)
	{
		++count;
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	Counter c1, c2;					   // define and initialize
	cout << "\nc1=" << c1.get_count(); // display
	cout << "\nc2=" << c2.get_count();
	++c1;							   // increment c1
	++c2;							   // increment c2
	++c2;							   // increment c2
	cout << "\nc1=" << c1.get_count(); // display again
	cout << "\nc2=" << c2.get_count() << endl;
	return 0;
}
