#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"

int main()
{
	// AMateria *mater[4];
	AMateria *cureMateria = new Cure();
	std::cout << *cureMateria ;
	delete cureMateria;

	    std::string kakes_name = "Kakes"; // Create an actual std::string variable

	ICharacter *kakes = new Character("Kakes");

}
