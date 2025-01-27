#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
private:
	const std::string default_type;
	const std::string default_sound;

protected:
public:
	Cat();
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
	~Cat();
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Cat const &infile);

#endif
