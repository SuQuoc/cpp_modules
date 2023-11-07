
#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
private: 


public:
	Cat(void);
	Cat(const Cat& src);
	Cat& operator = (const Cat& rhs);
	~Cat(void);

	void makeSound() const;

};