
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

//setters
void WrongCat::setIdeaAtIndex(const std::string& idea, unsigned int i)
{
	_brainPTR->setIdeaAtIndex(idea, i);
}

void WrongCat::setAllIdeas(const std::string& idea)
{
	_brainPTR->Brain::setAllIdeas(idea);
}

//getters
std::string WrongCat::getIdeaAtIndex(unsigned int i) const
{
	return (this->_brainPTR->Brain::getIdeaAtIndex(i));
}

//member functions
void WrongCat::makeSound() const
{
	std::cout << "WrongCat muuuuh muuuuuuh!" << std::endl;
}		

void WrongCat::coutIdeaAtIndex(unsigned int i) const
{
	std::cout << "💡 idea at index " << i << ": " << this->getIdeaAtIndex(i) << std::endl;
}


