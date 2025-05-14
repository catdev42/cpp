#include "Floor.hpp"
#include "AMateria.hpp"
#include <iostream>

/* Default constructor */
Floor::Floor() : capacity(DEFAULT_CAPACITY), size(DEFAULT_SIZE)
{
    std::cout << "Floor default constructor" << std::endl;
    items = new AMateria *[DEFAULT_CAPACITY];
    for (int i = 0; i < capacity; i++)
        items[i] = NULL;
    return;
}

/* Parametrized constructor */
Floor::Floor(AMateria *src) : capacity(DEFAULT_CAPACITY), size(DEFAULT_SIZE)
{
    std::cout << "Floor parametrized constructor" << std::endl;
    items = new AMateria *[DEFAULT_CAPACITY];
    initNullItems(items, capacity);
    return;
}

/* Destructor */
Floor::~Floor()
{
    std::cout << "Floor destructor" << std::endl;
    for (int i = 0; i < size; i++)
        if (items[i])
            delete items[i];
    delete items;
    return;
}

void Floor::addToFloor(AMateria *item)
{
    AMateria **newItems;
    if (size < capacity)
        for (int i = 0; i < capacity; i++)
        {
            if (items[i] == NULL)
            {
                items[i] = item;
                size++;
                return;
            }
        }
    int newCapacity = capacity * 2;
    newItems = new AMateria *[newCapacity];
    initNullItems(newItems, newCapacity);
    copyItems(newItems, capacity);
    size++;
    delete[] items;
    items = newItems;
}

/* Getters */
const AMateria **Floor::getItems() const
{
    return items;
}

const std::string &Floor::getTypeAtIndex(int index) const
{
    return items[index]->getType();
}

/* Stream operator overload */
// Prints the tipes of all stored items
std::ostream &operator<<(std::ostream &o, const Floor &infile)
{
    const int size = infile.getSize();
    const AMateria **items = infile.getItems();
    for (int i = 0; i < size; i++)
        o << items[i] << ", ";
    o << "." << std::endl;
    return o;
}

/***************************************/
/***************************************/
/* PRIVATE */

/* Copy constructor */
Floor::Floor(Floor const &src)
{
    std::cout << "Floor copy constructor: Impossible" << std::endl;
    return;
}

/* Assignment operator */
Floor &Floor::operator=(Floor const &rhs)
{
    std::cout << "Floor assignment operator : Impossible" << std::endl;
    return *this;
}

/* Private, internal copy function */
void Floor::copyItems(AMateria **newItems, int cap)
{
    for (int i = 0; i < cap; i++)
        newItems[i] = items[i];
}
void Floor::initNullItems(AMateria **newItems, int cap)
{
    for (int i = 0; i < cap; i++)
        newItems[i] = NULL;
}
