/* *********************************************************** */
/*         :::::::::: :::    :::          :::::::   ::::::::   */
/*        :+:        :+:    :+:         :+:   :+: :+:    :+:   */
/*       +:+         +:+  +:+          +:+   +:+        +:+    */
/*      +#++:++#     +#++:+           +#+   +:+     +#++:      */
/*     +#+         +#+  +#+          +#+   +#+        +#+      */
/*    #+#        #+#    #+#         #+#   #+# #+#    #+#       */
/*   ########## ###    ###          #######   ########         */
/* *********************************************************** */

#include "ClapTrap.hpp"

#include <iostream>
#include <sstream>

ClapTrap::ClapTrap(std::string name)
	: m_name(name), m_hp(10), m_ep(10), m_ad(0) {
#ifdef DEBUG
	std::cout << YEL << "ClapTrap default constructor called." << RES
			  << std::endl;
#endif
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad)
	: m_name(name), m_hp(hp), m_ep(ep), m_ad(ad) {
#ifdef DEBUG
	std::cout << YEL << "ClapTrap default constructor 2 called." << RES
			  << std::endl;
#endif
}

ClapTrap::ClapTrap(ClapTrap &ref) {
#ifdef DEBUG
	std::cout << YEL << "ClapTrap copy constructor called." << RES << std::endl;
#endif
	if (this != &ref) {
		this->m_name = ref.m_name;
		this->m_hp = ref.m_hp;
		this->m_ep = ref.m_ep;
		this->m_ad = ref.m_ad;
	}
}

ClapTrap &ClapTrap::operator=(ClapTrap &ref) {
#ifdef DEBUG
	std::cout << YEL << "ClapTrap copy assignment op called." << RES
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

ClapTrap::~ClapTrap(void) {
#ifdef DEBUG
	std::cout << YEL << "ClapTrap destructor called." << RES << std::endl;
#endif
}

void ClapTrap::attack(const std::string &target) {
	if (this->m_ep <= 0) {
		std::cout << MAG << this->m_name
				  << " tries to act, but alas, their energy reserves are as "
					 "empty as a Vogon’s soul"
				  << RES << "\n";
		return;
	}
	std::cout << BLU << this->m_name << " attempts to strike " << target
			  << " with the grace of a ballerina on roller skates, causing "
			  << this->m_ad << " points of damage!" << RES << "\n";
	this->m_ep--;  // Attack costs 1 point of energy
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->m_hp <= 0) {
		std::cout
			<< RED << this->m_name
			<< " could've suffered more, but doesn't have any hit points left."
			<< RES << "\n";
		return;
	} else if (this->m_hp - (int) amount <= 0) {
		std::cout << RED << this->m_name
				  << " has died. But don't panic! Well, actually... maybe "
					 "panic a little bit."
				  << RES << "\n";
	} else {
		std::cout << RED << "The universe delivers a slap in the form of "
				  << amount << " points of damage. " << this->m_name
				  << " wasn’t expecting it, but then again, who "
					 "expects the Spanish Inquisition?"
				  << RES << "\n";
	}
	this->m_hp -= amount;
	this->m_hp = std::max(this->m_hp, 0);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->m_ep <= 0) {
		std::cout << MAG << this->m_name
				  << " reached deep into the cosmic well of points… and come "
					 "up with a handful of absolutely nothing."
				  << RES << "\n";
		return;
	} else if (this->m_hp <= 0) {
		std::cout << MAG
				  << "A large blue whale, having recently pondered its "
					 "existence, lands on "
				  << this->m_name << " with great enthusiasm." << RES << "\n";
		std::cout << MAG
				  << "Unfortunately, they are now "
					 "beyond the help of even the most advanced repair systems."
				  << RES << "\n";
		return;
	} else {
		std::cout << GRN << "Miraculously " << this->m_name << " got +"
				  << amount << " of hit points. Must be their lucky towel."
				  << RES << "\n";
		this->m_hp += amount;
		this->m_ep--;
	}
}

std::string ClapTrap::getStats(void) {
	std::stringstream stats;
	stats << "ClapTrap " << this->m_name << ":\n";
	stats << "\tHP     : " << this->m_hp << "\n";
	stats << "\tEnergy : " << this->m_ep << "\n";
	stats << "\tAttack : " << this->m_ad << "\n";
	return stats.str();
}

std::string ClapTrap::getName(void) { return this->m_name; }
