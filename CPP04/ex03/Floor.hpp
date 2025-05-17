#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <iostream>
#include "AMateria.hpp"

/**
 * This class is not perfect:
 * Once on the floor, items CANNOT be picked up
 */

class Floor
{
public:
	static Floor& getInstance();
	~Floor();

	void addToFloor(AMateria *item);
	int getSize() const;
	const std::string &getTypeAtIndex(int index) const;

private:
	AMateria **items;
	int32_t capacity;
	int32_t size;
	enum
	{
		DEFAULT_SIZE = 0,
		DEFAULT_CAPACITY = 10
	};
	Floor();
	Floor(AMateria *src);
	Floor(Floor const &src);
	Floor &operator=(Floor const &rhs);

	void copyItems(AMateria **newItems, int cap);
	void initNullItems(AMateria **newItems, int cap);
};

std::ostream &operator<<(std::ostream &o, Floor const &infile);

#endif
