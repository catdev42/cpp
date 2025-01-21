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

class FragTrap : virtual public ClapTrap {
  public:
	FragTrap(std::string name);
	FragTrap(std::string name, int hp, int ep, int ad);
	FragTrap(FragTrap &ref);
	~FragTrap(void);

	FragTrap &operator=(FragTrap &ref);

	void highFivesGuys(void);
};
