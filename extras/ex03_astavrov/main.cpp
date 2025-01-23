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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(int ac, char *av[]) {
	(void) ac;
	(void) av;

	ClapTrap arthur("Arthur Dent", 42, 2, 9);
	ScavTrap ford("Ford Perfect");

	ford.guardeGate();
	arthur.attack(ford.getName());
	ford.takeDamage(9);

	std::cout << "\n" << arthur.getStats() << "\n";
	std::cout << ford.getStats() << "\n";

	arthur.takeDamage(43);
	ford.beRepaired(1);

	std::cout << "\n\n";

	arthur.beRepaired(100);

	std::cout << "\n" << arthur.getStats() << "\n";
	std::cout << ford.getStats() << "\n";

	ford.guardeGate();

	FragTrap zaphod("Zaphod Beeblebrox");

	zaphod.attack(ford.getName());
	ford.takeDamage(30);

	std::cout << "\n" << zaphod.getStats() << "\n";
	std::cout << ford.getStats() << "\n";

	zaphod.highFivesGuys();
	zaphod.attack(ford.getName());
	ford.takeDamage(30);

	std::cout << "\n" << zaphod.getStats() << "\n";
	std::cout << ford.getStats() << "\n";

	DiamondTrap marvin("Marvin");

	marvin.whoAmI();

	return 0;
}
