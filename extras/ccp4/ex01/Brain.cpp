#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}
Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = other.ideas[i]; // Perform deep copy
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.ideas[i]; // Deep copy
		}
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < numIdeas && index >= 0)
		return ideas[index];
	return "";
}
void Brain::setIdea(int index, const std::string &idea)
{
	if (index < numIdeas && index >= 0)
	{
		ideas[index] = idea;
	}
}
