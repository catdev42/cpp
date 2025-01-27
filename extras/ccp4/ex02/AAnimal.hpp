#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string& type); //parameterized constructor
		AAnimal(const AAnimal& other); //copy constructor
		AAnimal& operator=(const AAnimal& other); //assignment operator
		virtual ~AAnimal(); //virtual destructor
		virtual void makeSound() const = 0; //pure virtual function
		std::string getType() const; //getter
};

#endif
