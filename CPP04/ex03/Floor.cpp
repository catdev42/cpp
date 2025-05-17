#include "Floor.hpp"
#include "AMateria.hpp"
#include <iostream>

Floor &Floor::getInstance()
{
    static Floor instance; // Meyers' Singleton: created on first call, destroyed at program exit
    return instance;
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

/********************************************/
/********************************************/
/******MEMBER FUNCTIONS******/

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

int Floor::getSize() const
{
    return size;
}

const std::string &Floor::getTypeAtIndex(int index) const
{
    if (index > 0 && index < size)
        return items[index]->getType();
    static const std::string error_str = "Error: not a valid index";
    return error_str;
}

/* Stream operator overload */
// Prints the tipes of all stored items
std::ostream &operator<<(std::ostream &o, const Floor &infile)
{
    const int size = infile.getSize();
    for (int i = 0; i < size; i++)
        o << infile.getTypeAtIndex(i) << ", ";
    o << "." << std::endl;
    return o;
}

/***************************************/
/***************************************/
/* PRIVATE */

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
    addToFloor(src);
    return;
}

/* Copy constructor */
Floor::Floor(Floor const &src)
{
    std::cout << "Floor copy constructor: Impossible"
              << src.size << " items are on the floor and there is only ONE floor"
              << std::endl;

    return;
}

/* Assignment operator */
Floor &Floor::operator=(Floor const &rhs)
{
    std::cout << "Floor assignment operator : Impossible"
              << rhs.size << " items are on the floor and there is only ONE floor"
              << std::endl;
    return *this;
}

// Internal

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
