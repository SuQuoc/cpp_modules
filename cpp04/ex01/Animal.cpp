
#include "Animal.hpp"

//Canonical form
Animal::Animal (void)
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal (const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal& Animal::operator = (const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

Animal::~Animal (void)
{
    std::cout << "Animal destructor called" << std::endl;
}

//parametric constructor
Animal::Animal (const std::string& type)
{
    std::cout << "Animal default constructor called" << std::endl;
	this->type = type;
}


void Animal::setType(const std::string& type)
{
	this->type = type;
}

std::string Animal::getType() const
{
	return this->type;
}



void Animal::makeSound(void) const
{
	std::cout << "ANIMAL SOUND!" << std::endl;
}

