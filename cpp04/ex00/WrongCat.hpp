
#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private: 


public:
	WrongCat(void);
	WrongCat(const WrongCat& src);
	WrongCat& operator = (const WrongCat& rhs);
	~WrongCat(void);

	void makeSound() const;
};