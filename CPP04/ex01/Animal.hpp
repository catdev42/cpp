#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
private:
protected:
	std::string type;

public:
	Animal();
	Animal(Animal const &src);
	Animal &operator=(Animal const &rhs);
	virtual ~Animal();

	// Getters & Setters
	std::string getType() const;

	// Member functions
	virtual void makeSound() const;
	virtual void makeSoundToStream(std::ostream &o) const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, const Animal &infile);
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
