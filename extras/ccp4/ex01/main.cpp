#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int arraySize = 4;
	Animal *animals[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	Dog *dog = new Dog();
	dog->getBrain()->setIdea(0, "I am a dog");
	Dog *dog_copy = new Dog(*dog);
	dog_copy->getBrain()->setIdea(0, "I am just a clone of the dog");
	std::cout << "Dog says: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog copy says: " << dog_copy->getBrain()->getIdea(0) << std::endl;
	delete dog;
	delete dog_copy;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
	return 0;
}
