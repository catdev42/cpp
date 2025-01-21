#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    return 0;
}