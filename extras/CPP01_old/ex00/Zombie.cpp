#include "Zombie.hpp"
#include <iostream>

//  private:
// std::string _name;

//   public:

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(std::string name_given) : _name(name_given)
{
	std::cout << _name << " zombie created" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << _name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
