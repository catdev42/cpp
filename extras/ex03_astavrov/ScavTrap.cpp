/* *********************************************************** */
/*         :::::::::: :::    :::          :::::::   ::::::::   */
/*        :+:        :+:    :+:         :+:   :+: :+:    :+:   */
/*       +:+         +:+  +:+          +:+   +:+        +:+    */
/*      +#++:++#     +#++:+           +#+   +:+     +#++:      */
/*     +#+         +#+  +#+          +#+   +#+        +#+      */
/*    #+#        #+#    #+#         #+#   #+# #+#    #+#       */
/*   ########## ###    ###          #######   ########         */
/* *********************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20), m_guardeModeOn(false) {
#ifdef DEBUG
	std::cout << YEL << "ScavTrap constructor called." << RES << std::endl;
#endif
}

ScavTrap::ScavTrap(std::string name, int hp, int ep, int ad)
	: ClapTrap(name, hp, ep, ad), m_guardeModeOn(false) {
#ifdef DEBUG
	std::cout << YEL << "ScavTrap constructor 2 called." << RES << std::endl;
#endif
}

ScavTrap::ScavTrap(ScavTrap &ref) : ClapTrap(ref) {
#ifdef DEBUG
	std::cout << YEL << "ScavTrap copy constructor called." << RES << std::endl;
#endif
	if (this != &ref)
		this->m_guardeModeOn = ref.m_guardeModeOn;
}

ScavTrap &ScavTrap::operator=(ScavTrap &ref) {
#ifdef DEBUG
	std::cout << YEL << "ScavTrap copy assignment op called." << RES
			  << std::endl;
#endif
	if (this != &ref) {
		this->m_name = ref.m_name;
		this->m_hp = ref.m_hp;
		this->m_ep = ref.m_ep;
		this->m_ad = ref.m_ad;
		this->m_guardeModeOn = ref.m_guardeModeOn;
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
#ifdef DEBUG
	std::cout << YEL << "ScavTrap destructor called." << RES << std::endl;
#endif
}

void ScavTrap::attack(const std::string &target) {
	if (this->m_ep <= 0) {
		std::cout << MAG << this->m_name
				  << "’s points are lower than Zaphod’s sense of "
					 "responsibility - nonexistent."
				  << RES << "\n";
		return;
	}
	std::cout << BLU << "With the precision of a Vogon poetry recital, "
			  << this->m_name
			  << " launches "
				 "an attack. "
			  << target << " receives " << this->m_ad
			  << " points of damage . The universe winces." << RES << "\n";
	this->m_ep--;  // Attack costs 1 point of energy
}

void ScavTrap::guardeGate(void) {
	this->m_guardeModeOn = !this->m_guardeModeOn;
	if (this->m_guardeModeOn) {
		std::cout
			<< GRN << this->m_name
			<< " braces themself for incoming chaos, preparing to guard like a "
			   "paranoid android with a grudge against the universe."
			<< RES << "\n";
	} else {
		std::cout << GRN << this->m_name
				  << " relaxes their guard, trusting that the universe "
					 "probably won’t drop another whale on them... probably."
				  << RES << "\n";
	}
}
