#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
private:
protected:
public:
	Cat();
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
	~Cat();
	void makeSound() const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Cat const &infile);

#endif
