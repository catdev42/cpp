#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
private:
	const std::string default_type;
	const std::string default_sound;

protected:
public:
	Dog();
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog();
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Dog const &infile);

#endif
