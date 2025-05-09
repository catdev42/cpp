#include "Brain.hpp"
#include <iostream>

// Default constructor
Brain::Brain()
{
	std::cout << "Brain default constructor was called" << std::endl;
	return;
}

// Copy constructor
Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor was called" << std::endl;
	std::copy(src.ideas, src.ideas + MAX, ideas);
	return;
}

// Assignment operator
Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignment operator was called" << std::endl;
	if (this != &rhs)
		std::copy(rhs.ideas, rhs.ideas + MAX, ideas);
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor was called" << std::endl;
	return;
}

/*****SET and GET*****/

void Brain::setOneIdea(const std::string &idea)
{
	for (int i = 0; i < MAX; i++)
	{
		if (ideas[i].empty())
		{
			ideas[i] = idea;
			return;
		}
		if (i == 99)
		{
			std::cout << "Brain is too full to add more" << std::endl;
		}
	}
}

void Brain::replaceOneIdea(const std::string &idea, size_t index)
{
	if (index < MAX)
		ideas[index] = idea;
	else
	{
		std::cout << "This Index Does Not Exist Meow" << std::endl;
	}
}

const std::string *Brain::getIdeas() const
{
	return ideas;
}

/*******MEMBER FUNCTIONS***********/
void Brain::printIdeas(std::ostream &o) const
{
	for (int i = 0; i < MAX; i++)
	{
		if (!ideas[i].empty())
			o << ideas[i] << " " << std::endl;
	}
}

void Brain::printIdeas() const
{
	for (int i = 0; i < MAX; i++)
	{
		if (!ideas[i].empty())
			std::cout << ideas[i] << " " << std::endl;
	}
}

void Brain::copy_into_self(const Brain &other)
{
	std::copy(other.ideas, other.ideas + MAX, ideas);
}

// STREAM OPERATOR OVERLOAD
std::ostream &operator<<(std::ostream &o, Brain const &infile)
{
	infile.printIdeas(o);
	return o;
}
