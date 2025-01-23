/* *********************************************************** */
/*         :::::::::: :::    :::          :::::::   ::::::::   */
/*        :+:        :+:    :+:         :+:   :+: :+:    :+:   */
/*       +:+         +:+  +:+          +:+   +:+        +:+    */
/*      +#++:++#     +#++:+           +#+   +:+     +#++:      */
/*     +#+         +#+  +#+          +#+   +#+        +#+      */
/*    #+#        #+#    #+#         #+#   #+# #+#    #+#       */
/*   ########## ###    ###          #######   ########         */
/* *********************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name),
	  FragTrap(name) {
	this->m_name = name;
#ifdef DEBUG
	std::cout << YEL << "DiamondTrap default constructor called." << RES
			  << std::endl;
#endif
}

DiamondTrap::DiamondTrap(std::string name, int hp, int ep, int ad)
	: ClapTrap(name + "_clap_name", hp, ep, ad), ScavTrap(name),
	  FragTrap(name) {
	this->m_name = name;
#ifdef DEBUG
	std::cout << YEL << "DiamondTrap default constructor 2 called." << RES
			  << std::endl;
#endif
}

DiamondTrap::DiamondTrap(DiamondTrap &ref)
	: ClapTrap(ref), ScavTrap(ref), FragTrap(ref) {
#ifdef DEBUG
	std::cout << YEL << "DiamondTrap copy constructor called." << RES
			  << std::endl;
#endif
	if (this != &ref)
		this->m_name = ref.m_name;
}

DiamondTrap::~DiamondTrap(void) {
#ifdef DEBUG
	std::cout << YEL << "DiamondTrap destructor called." << RES << std::endl;
#endif
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &ref) {
#ifdef DEBUG
	std::cout << YEL << "DiamondTrap copy assignment op called." << RES
			  << std::endl;
#endif
	if (this != &ref) {
		this->m_name = ref.m_name;
		this->m_hp = ref.m_hp;
		this->m_ep = ref.m_ep;
		this->m_ad = ref.m_ad;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << MAG << "Greetings, interstellar traveler! I am " << this->m_name 
			  << ", and in a parallel dimension, my ClapTrap designation is "
			  << this->ClapTrap::getName() << ". Don't panic!" << RES << std::endl;
}
