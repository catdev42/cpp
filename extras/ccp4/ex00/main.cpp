#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal(); // Create an Animal object
	const Animal *j = new Dog();       // Create a Dog object
	const Animal *i = new Cat();       // Create a Cat object

	std::cout << j->getType() << " " << std::endl; // Print type of Dog
	std::cout << i->getType() << " " << std::endl; // Print type of Cat

	i->makeSound();    // Cat sound
	j->makeSound();    // Dog sound
	meta->makeSound(); // Generic Animal sound

  	const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << "---- wrong->MakeSound " << wrongI->getType() << " " << std::endl;

    wrongI->makeSound();  // This will call WrongAnimal::makeSound() because it's not virtual
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongI;


	// Clean up memory
	delete meta;
	delete j;
	delete i;

	return 0;
}
