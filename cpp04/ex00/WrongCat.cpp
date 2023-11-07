
#include "WrongCat.hpp"

//Canonical form
WrongCat::WrongCat (void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat (const WrongCat& src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator = (const WrongCat& rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

WrongCat::~WrongCat (void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat muuuuh muuuuuuh!" << std::endl;
}		

