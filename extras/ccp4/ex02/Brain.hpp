#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain
{
  private:
	static const int numIdeas = 100; // Define the constant
	std::string ideas[numIdeas];

  public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string getIdea(int index) const;
	void setIdea(int index, const std::string &idea);
};

#endif
