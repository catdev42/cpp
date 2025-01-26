#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

// TODO: write tester
int main()
{

    ScavTrap scavvy("Scavvy");
    scavvy.guardGate();
    scavvy.attack("Clappy");
    scavvy.beRepaired(2);
    scavvy.takeDamage(8);

    std::cout << std::endl;

    FragTrap fraggy("Fraggy");
    fraggy.highFiveGuys();
    fraggy.attack("MOOOO");
    fraggy.beRepaired(2);
    fraggy.takeDamage(8);

    std::cout << std::endl;

    DiamondTrap dia("Dia");
    dia.attack("MOOOO");
    dia.beRepaired(2);
    dia.takeDamage(8);
    dia.whoAmI();
    std::cout << dia << std::endl;

    DiamondTrap dia2(dia);
    dia2.setNewName("Dia2");
    dia2.guardGate();
    dia2.whoAmI();
    std::cout << dia2 << std::endl;

    // ScavTrap scavvy2 = scavvy;
    // scavvy2.setNewName("Scavvy2");
    // ScavTrap scavvy3 = dia;
    // scavvy3.setNewName("Scavvy3");

    return 0;
}
