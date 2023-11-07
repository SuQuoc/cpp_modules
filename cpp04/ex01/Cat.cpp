
#include "Cat.hpp"

//Canonical form
Cat::Cat (void): Animal("Cat")
{
    this->_brainPTR = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat (const Cat& src)
{
    this->_brainPTR = new Brain();
    std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator = (const Cat& rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	(*this->_brainPTR) = (*rhs._brainPTR);
	return *this;
}

Cat::~Cat (void)
{
	delete this->_brainPTR;
    std::cout << "Cat destructor called" << std::endl;
}

//setters
void Cat::setIdeaAtIndex(const std::string& idea, unsigned int i)
{
	_brainPTR->setIdeaAtIndex(idea, i);
}

void Cat::setAllIdeas(const std::string& idea)
{
	_brainPTR->Brain::setAllIdeas(idea);
}

//getters
std::string Cat::getIdeaAtIndex(unsigned int i) const
{
	return (this->_brainPTR->Brain::getIdeaAtIndex(i));
}

//member functions
void Cat::makeSound() const
{
	std::cout << "Miau miau!" << std::endl;
}		

void Cat::coutIdeaAtIndex(unsigned int i) const
{
	std::cout << "💡 idea at index " << i << ": " << this->getIdeaAtIndex(i) << std::endl;
}


