/* *********************************************************** */
/*         :::::::::: :::    :::          :::::::   ::::::::   */
/*        :+:        :+:    :+:         :+:   :+: :+:    :+:   */
/*       +:+         +:+  +:+          +:+   +:+        +:+    */
/*      +#++:++#     +#++:+           +#+   +:+     +#++:      */
/*     +#+         +#+  +#+          +#+   +#+        +#+      */
/*    #+#        #+#    #+#         #+#   #+# #+#    #+#       */
/*   ########## ###    ###          #######   ########         */
/* *********************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
#ifdef DEBUG
	std::cout << YEL << "FragTrap default constructor called." << RES
			  << std::endl;
#endif
}

FragTrap::FragTrap(std::string name, int hp, int ep, int ad)
	: ClapTrap(name, hp, ep, ad) {
#ifdef DEBUG
	std::cout << YEL << "FragTrap default constructor 2 called." << RES
			  << std::endl;
#endif
}

FragTrap::FragTrap(FragTrap &ref) : ClapTrap(ref) {
#ifdef DEBUG
	std::cout << YEL << "FragTrap copy constructor called." << RES << std::endl;
#endif
}

FragTrap::~FragTrap(void) {
#ifdef DEBUG
	std::cout << YEL << "FragTrap destructor called." << RES << std::endl;
#endif
}

FragTrap &FragTrap::operator=(FragTrap &ref) {
#ifdef DEBUG
	std::cout << YEL << "FragTrap copy assignment op called." << RES
			  << std::endl;
#endif
	this->ClapTrap::operator=(ref);
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << MAG << "FragTrap " << this->getName()
			  << " extends a cheerful high five to all sentient beings in the "
				 "vicinity!"
			  << RES << std::endl;
}
