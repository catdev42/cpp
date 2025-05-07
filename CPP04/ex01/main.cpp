#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

// In your main function, create and fill an array of Animal objects. Half of it will
// be Dog objects and the other half will be Cat objects. At the end of your program
// execution, loop over this array and delete every Animal. You must delete directly dogs
// and cats as Animals. The appropriate destructors must be called in the expected order.

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

/*
const Animal *animal = new Animal();
std::cout << animal->getType() << " " << std::endl;
animal->makeSound();

const Animal *dogAnimal = new Dog();
std::cout << dogAnimal->getType() << " " << std::endl;
dogAnimal->makeSound();

const Animal *kitty = new Cat();
std::cout << kitty->getType() << " " << std::endl;
std::cout << "class Animal kitty says ";
kitty->makeSound(); // will output the cat sound!

const Cat *kittyCat =  new Cat();
std::cout << "class Cat kittyCat says ";
kittyCat->makeSound();

delete kitty;
delete animal;

std::cout << std::endl; */

/*
const WrongAnimal *wrongmeta = new WrongAnimal();
const WrongAnimal *wrongi = new WrongCat();


std::cout << wrongi->getType() << " " << std::endl;
wrongi->makeSound(); // will NOT output the cat sound!

std::cout << wrongmeta->getType() << " " << std::endl;
wrongmeta->makeSound();

//check cat class directly
const WrongCat *catAsCat = new WrongCat();
std::cout << catAsCat->getType() << " " << std::endl;
catAsCat->makeSound();

delete wrongmeta;
delete wrongi;
delete catAsCat;
*/
