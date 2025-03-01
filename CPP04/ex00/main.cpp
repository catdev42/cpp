// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"
#include "Animal.hpp"
// #include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

int main()
{
	const Animal *animal = new Animal();
	std::cout << animal->getType() << " " << std::endl;
	animal->makeSound();

	// const Animal *j = new Dog();
	// std::cout << j->getType() << " " << std::endl;
	// j->makeSound();

	const Animal *kitty = new Cat();
	std::cout << kitty->getType() << " " << std::endl;
	std::cout << "class Animal kitty says ";
	kitty->makeSound(); // will output the cat sound!

	const Cat *kittyCat =  new Cat();
	std::cout << "class Cat kittyCat says ";
	kittyCat->makeSound();

	std::cout << std::endl;

	delete kitty;
	delete animal;


	// const WrongAnimal *wrongmeta = new WrongAnimal();
	// const WrongAnimal *wrongi = new WrongCat();


	// std::cout << wrongi->getType() << " " << std::endl;
	// wrongi->makeSound(); // will output the cat sound!

	// std::cout << wrongmeta->getType() << " " << std::endl;
	// wrongmeta->makeSound();
}
