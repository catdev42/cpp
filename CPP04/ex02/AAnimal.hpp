#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
private:
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(AAnimal const &src);
	AAnimal &operator=(AAnimal const &rhs);
	virtual ~AAnimal();

	// Getters & Setters
	std::string getType() const;

	// Member functions
	virtual void makeSound() const = 0;
	virtual void makeSound(std::ostream &o) const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, const AAnimal &infile);
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
