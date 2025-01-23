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

#include <iostream>
#include <string>

class ClapTrap {
  public:
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hp, int ep, int ad);
	ClapTrap(ClapTrap &ref);
	ClapTrap &operator=(ClapTrap &ref);
	~ClapTrap(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getStats(void);
	std::string getName(void);

  protected:
	std::string m_name;
	int m_hp;  // Health points
	int m_ep;  // Energy points
	int m_ad;  // Attack damage
};

#ifndef __42__COLORS__
#define __42__COLORS__
#define RES "\033[0m"
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"
#endif
