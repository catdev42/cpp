#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#ifndef COLORS
#define COLORS
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

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal &operator=(WrongAnimal const &rhs);
	virtual ~WrongAnimal(); 

	std::string getType() const;
	void makeSound() const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, WrongAnimal const &infile);

#endif
