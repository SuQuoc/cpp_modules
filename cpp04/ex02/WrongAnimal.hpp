
#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

private: 


public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal& operator = (const WrongAnimal& rhs);
	virtual ~WrongAnimal(void);

	WrongAnimal (std::string type);

	std::string getType() const;
	virtual void makeSound() const = 0;
};