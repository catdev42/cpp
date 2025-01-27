#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
private:
	const std::string default_type;
	const std::string default_sound;

protected:
	std::string sound;
	std::string type;

public:
	Animal();
	Animal(Animal const &src);
	Animal &operator=(Animal const &rhs);
	~Animal();

	std::string getType() const;
	void makeSound() const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Animal const &infile);

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

#endif
