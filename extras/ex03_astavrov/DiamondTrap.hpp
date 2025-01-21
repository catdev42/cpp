/* *********************************************************** */
/*         :::::::::: :::    :::          :::::::   ::::::::   */
/*        :+:        :+:    :+:         :+:   :+: :+:    :+:   */
/*       +:+         +:+  +:+          +:+   +:+        +:+    */
/*      +#++:++#     +#++:+           +#+   +:+     +#++:      */
/*     +#+         +#+  +#+          +#+   +#+        +#+      */
/*    #+#        #+#    #+#         #+#   #+# #+#    #+#       */
/*   ########## ###    ###          #######   ########         */
/* *********************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
	DiamondTrap(std::string name);
	DiamondTrap(std::string name, int hp, int ep, int ad);
	DiamondTrap(DiamondTrap &ref);
	~DiamondTrap(void);

	DiamondTrap &operator=(DiamondTrap &ref);

	using ScavTrap::attack;
	void whoAmI(void);

  private:
	std::string m_name;
};
