
#include "WrongAnimal.hpp"

//Canonical form
WrongAnimal::WrongAnimal (void)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal (void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

//parametric constructor
WrongAnimal::WrongAnimal (std::string type)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = type;
}


std::string WrongAnimal::getType() const
{
	return this->type;
}



void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongANIMAL SOUND!" << std::endl;
}

