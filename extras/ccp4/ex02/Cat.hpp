#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
  private:
	Brain *brain;
  public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	// Cat(std::string type);
	void makeSound(void) const;
	Brain* getBrain() const;
};

#endif
