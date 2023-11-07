
#include "Cat.hpp"

//Canonical form
Cat::Cat (void): Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat (const Cat& src)
{
    std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator = (const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	return *this;
}

Cat::~Cat (void)
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miau miau!" << std::endl;
}		

