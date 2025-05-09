#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
private:
	Brain *brain;

protected:
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog();

	// Getters & Setters
	std::string getType() const;

	// Member functions
	void makeSound() const;
	void makeSound(std::ostream &o) const;

	void giveIdea(const std::string &animalIdeas);
	
	void printIdeas() const;
	void printIdeas(std::ostream &o) const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile);

#endif

// Uncomment if you need colors
/*
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
*/
