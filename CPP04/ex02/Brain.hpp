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

	void copy_into_self(const Brain &other);
	// Getters & Setters
	void setOneIdea(const std::string &animalIdea);
	void replaceOneIdea(const std::string &idea, size_t index);
	const std::string *getIdeas() const;
	// const std::string &getOneIdea(const std::string &idea, size_t index) const;

	// Member functions
	void printIdeas() const;
	void printIdeas(std::ostream &o) const;
};

// Stream operator overload
std::ostream &operator<<(std::ostream &o, Brain const &infile);

#endif
