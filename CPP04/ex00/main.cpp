#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

int main()
{
	const Animal *animal = new Animal();
	std::cout << animal->getType() << " " << std::endl;
	animal->makeSound();

	const Animal *j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	const Animal *kitty = new Cat();
	std::cout << kitty->getType() << " " << std::endl;
	std::cout << "class Animal kitty says ";
	kitty->makeSound(); // will output the cat sound!

	const Cat *kittyCat = new Cat();
	std::cout << "class Cat kittyCat says ";
	kittyCat->makeSound();

	delete kitty;
	delete animal;

	std::cout << std::endl;

	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *wrongi = new WrongCat();

	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); // will NOT output the cat sound!

	std::cout << wrongmeta->getType() << " " << std::endl;
	wrongmeta->makeSound();

	const WrongCat *catAsCat = new WrongCat();

	std::cout << catAsCat->getType() << " USED AS CAT CLASS";
	catAsCat->makeSound();
	std::cout << std::endl;

	delete wrongmeta;
	delete wrongi;
	delete catAsCat;
}
