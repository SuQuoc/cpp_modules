
#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
private: 


public:
	Dog(void);
	Dog(const Dog& src);
	Dog& operator = (const Dog& rhs);
	~Dog(void);

	void makeSound() const;

};