#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

/*
RUN VALGRIND WITH "make check"
In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
*/

int main()
{
	static const int max = 100;
	Animal *animals[max];
	for (int i = 0; i < max / 2; i++)
		animals[i] = new Cat();
	for (int i = max / 2; i < max; i++)
		animals[i] = new Dog();

	for (int i = 0; i < max; i++)
		delete animals[i];
}
