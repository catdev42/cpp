#include <iostream>

struct Employee
{
    // Define an enumeration type inside the struct
    enum Empl_type
    {
        M,
        E
    }; // M and E are possible values (maybe Manager and Employee?)
    Empl_type type; // Member variable of the enum type

    // Default constructor that initializes type to E
    Employee() : type(E) {} // Use initialization list to set type to E

    // Member variables
    string first_name, family_name; // Two string members for names
    char middle_initial;            // Single character for middle initial
    Date hiring_date;               // Date object to store hiring date
    short department;               // Department number stored as short int (2 bytes)
};

struct Manager : public Employee
{
    Manager() { type = M; }
    set<Employee *> group; // people managed short level;
    //...
};

void print_employee(const Employee *e)
{

    switch (e->type)
    {
    case Employee::E:
    {
        std::cout << e->family_name << ' \t ' << e->department << '\n '; //...
        break;
    }
    case Employee::M:
    {
        std::cout << e->family_name << ' \t ' << e->department << '\n '; //...
        const Manager *p = static_cast<const Manager *>(e);
        std::cout << " level " << p->level << '\n' ́;
        //...
        break;
    }
    }
}
