#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"

/*
RUN VALGRIND WITH "make check"
In your main function, create and fill an array of AAnimal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every AAnimal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
*/

int main()
{
	static const int max = 100;
	AAnimal *animals[max];

	for (int i = 0; i < max / 2; i++)
	{
		animals[i] = new Cat();
		if (i == 1)
		{
			dynamic_cast<Cat *>(animals[1])->giveIdea("Meow Mew Mew");
		}
		if (i == 3)
		{
			delete animals[3];
			animals[3] = new Cat(*(dynamic_cast<Cat *>(animals[1])));
			// animals[3] = new Cat(animals[1]);

			std::cout << GREEN << "Test Deep Copy:" << std::endl;
			dynamic_cast<Cat *>(animals[3])->printIdeas();
			std::cout << RESET;
		}
	}
	for (int i = max / 2; i < max; i++)
		animals[i] = new Dog();

	animals[10]->makeSound();
	animals[70]->makeSound();

	for (int i = 0; i < max; i++)
		delete animals[i];
}
