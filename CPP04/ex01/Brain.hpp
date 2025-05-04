#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	static const int MAX = 100;

protected:
	std::string ideas[MAX];

public:
	Brain();
	Brain(Brain const &src);
	Brain &operator=(Brain const &rhs);
	~Brain();

	// Getters & Setters

	// Member functions
	void copy_into_self(const Brain& other)
	{
		std::copy(other.ideas, other.ideas + MAX, ideas);
	}
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Brain const &infile);

#endif
