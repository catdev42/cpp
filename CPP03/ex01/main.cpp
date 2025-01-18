#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // Create ClapTrap objects
    ClapTrap nameless;
    ClapTrap named("Clappy");
    ClapTrap copy(named);

    // Test attack function
    named.attack("target1");
    named.attack("target2");

    // Test takeDamage function
    named.takeDamage(5);
    named.takeDamage(6);

    // Test beRepaired function
    named.beRepaired(3);
    named.beRepaired(2);

    // Test energy depletion
    for (int i = 0; i < 10; ++i) {
        named.attack("target" + std::to_string(i + 3));
    }

    // Test attack with no energy
    named.attack("target13");

    // Test repair with no energy
    named.beRepaired(5);

    return 0;
}
