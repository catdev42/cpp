#include "Character.h"
#include "Cure.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>

int main()
{
	// Create a MateriaSource and learn some Materias
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create a character
	ICharacter *me = new Character("me");

	// Create some Materias and equip them
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice"); // Try equipping more than 4
	me->equip(tmp);
	tmp = src->createMateria("cure"); // Try equipping more than 4
	me->equip(tmp);
	tmp = src->createMateria("ice"); // Try equipping more than 4
	me->equip(tmp);                  // This should fail or not do anything

	// Create another character
	ICharacter *bob = new Character("bob");

	// Use the equipped Materias
	std::cout << "\n=== Testing basic Materia use ===" << std::endl;
	me->use(0, *bob); // Should shoot ice
	me->use(1, *bob); // Should heal
	me->use(2, *bob); // Should do nothing, as this slot is not equipped
	me->use(3, *bob); // Should do nothing, as this slot is not equipped

	// Test unequip
	std::cout << "\n=== Testing unequip ===" << std::endl;
	me->unequip(0);   // Unequip ice
	me->use(0, *bob); // Should do nothing as slot is empty

	// Test copy constructor
	std::cout << "\n=== Testing copy constructor ===" << std::endl;
	Character *jim = new Character("jim");
	tmp = src->createMateria("ice");
	jim->equip(tmp);
	Character *jimClone = new Character(*jim);

	// Test that clone works properly
	jim->use(0, *bob);      // Should shoot ice
	jimClone->use(0, *bob); // Should also shoot ice

	// Clean up
	delete bob;
	delete me;
	delete jim;
	delete jimClone;
	delete src;

	return 0;
}
