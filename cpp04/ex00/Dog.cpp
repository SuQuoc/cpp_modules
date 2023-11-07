
#include "Dog.hpp"

//Canonical form
Dog::Dog (void): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog (const Dog& src)
{
    std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator = (const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

Dog::~Dog (void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wuff wuff!" << std::endl;
}