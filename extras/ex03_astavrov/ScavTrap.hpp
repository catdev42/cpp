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

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

class ScavTrap : virtual public ClapTrap {
  public:
	ScavTrap(std::string name);
	ScavTrap(std::string name, int hp, int ep, int ad);
	ScavTrap(ScavTrap &ref);
	ScavTrap &operator=(ScavTrap &ref);
	~ScavTrap(void);

	void guardeGate(void);
	void attack(const std::string &target);

  private:
	bool m_guardeModeOn;
};
