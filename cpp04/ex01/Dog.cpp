
#include "Dog.hpp"

//Canonical form
Dog::Dog (void): Animal("Dog")
{
    this->_brainPTR = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog (const Dog& src)
{
    this->_brainPTR = new Brain();
    std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator = (const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->type = rhs.type;
	(*this->_brainPTR) = (*rhs._brainPTR);
	return *this;
}


//setters
void Dog::setIdeaAtIndex(const std::string& idea, unsigned int i)
{
	_brainPTR->setIdeaAtIndex(idea, i);
}

void Dog::setAllIdeas(const std::string& idea)
{
	_brainPTR->Brain::setAllIdeas(idea);
}


Dog::~Dog (void)
{
	delete this->_brainPTR;
    std::cout << "Dog destructor called" << std::endl;
}

//getters
std::string Dog::getIdeaAtIndex(unsigned int i) const
{
	return (this->_brainPTR->Brain::getIdeaAtIndex(i));
}

//member functions
void Dog::makeSound() const
{
	std::cout << "Wuff wuff!" << std::endl;
}

void Dog::coutIdeaAtIndex(unsigned int i) const
{
	std::cout << "💡 idea at index " << i << ": " << this->getIdeaAtIndex(i) << std::endl;
}
