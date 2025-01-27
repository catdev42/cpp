#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Create Dog and Cat objects with their Brain instances
	Dog *dog1 = new Dog();
	Cat *cat1 = new Cat();

	// Set some ideas in the Dog and Cat brains
	dog1->getBrain()->setIdea(0, "Chase the ball");
	dog1->getBrain()->setIdea(1, "Bark at the neighbor");

	cat1->getBrain()->setIdea(0, "Chase the mouse");
	cat1->getBrain()->setIdea(1, "Sleep all day");

	// Display ideas from Dog and Cat's Brain
	std::cout << "Dog 1's first idea: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog 1's second idea: " << dog1->getBrain()->getIdea(1) << std::endl;

	std::cout << "Cat 1's first idea: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 1's second idea: " << cat1->getBrain()->getIdea(1) << std::endl;

	// Test deep copy functionality for Dog and Cat
	Dog *dog2 = new Dog(*dog1); // Copy constructor for Dog
	Cat *cat2 = new Cat(*cat1); // Copy constructor for Cat

	// Modify original Dog and Cat brains to ensure deep copy worked
	dog1->getBrain()->setIdea(0, "Sleep in the sun");
	cat1->getBrain()->setIdea(0, "Play with the yarn");

	// Check if copied Dog and Cat brains remain unchanged
	std::cout << "Dog 2's first idea (should be original idea): " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2's first idea (should be original idea): " << cat2->getBrain()->getIdea(0) << std::endl;

	// Check if original Dog and Cat brains were modified
	std::cout << "Dog 1's modified first idea: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 1's modified first idea: " << cat1->getBrain()->getIdea(0) << std::endl;

	// Test polymorphism and makeSound function
	dog1->makeSound();
	cat1->makeSound();

	// Extra: Accessing ideas out of bounds (optional, to see if it handles gracefully)
	std::cout << "Accessing out-of-bounds idea from Dog: " << dog1->getBrain()->getIdea(101) << std::endl; // Should handle gracefully
	dog1->getBrain()->setIdea(101, "Should not work");                                                     // Should handle gracefully

	// Cleanup memory for dog1 and cat1
	delete dog1;
	delete cat1;

	// Extra Test: Verify that deleting through AAnimal* does not leak memory
	const AAnimal *AAnimalDog = new Dog();
	const AAnimal *AAnimalCat = new Cat();

	// Deleting via base class pointer
	delete AAnimalDog; // Should call Dog's and Brain's destructors
	delete AAnimalCat; // Should call Cat's and Brain's destructors

	// Clean up memory for dog2 and cat2
	delete dog2;
	delete cat2;

	// Extra: Test polymorphism using an array of AAnimal*
	AAnimal *AAnimals[4];
	AAnimals[0] = new Dog();
	AAnimals[1] = new Cat();
	AAnimals[2] = new Dog();
	AAnimals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		AAnimals[i]->makeSound(); // Calls correct sound based on the object type
	}

	// Cleanup memory for AAnimals array
	for (int i = 0; i < 4; i++)
	{
		delete AAnimals[i]; // Ensure proper deletion without memory leaks
	}

	return 0;
}
