#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "AAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
private:
protected:
public:
	WrongCat();
	WrongCat(WrongCat const &src);
	WrongCat &operator=(WrongCat const &rhs);
	~WrongCat();
	void makeSound() const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, WrongCat const &infile);

#endif
