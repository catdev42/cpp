#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl;


	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *wrongi = new WrongCat();


	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); // will output the cat sound!

	std::cout << wrongmeta->getType() << " " << std::endl;
	wrongmeta->makeSound();
}
