#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
private:
protected:
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog();
	void makeSound() const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile);

#endif
