
#include "Brain.hpp"
 
//Canonical form
Brain::Brain (void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain (const Brain& src)
{
    std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain& Brain::operator = (const Brain& rhs)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}

Brain::~Brain (void)
{
    std::cout << "Brain destructor called" << std::endl;
}


//setters
void Brain::setIdeaAtIndex(const std::string& idea, unsigned int i)
{
	if (i > 99)
	{
		std::cout << "Index cant be over 99" << std::endl;
		return ;
	}
	_ideas[i] = idea;
}

void Brain::setAllIdeas(const std::string& idea)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}


std::string Brain::getIdeaAtIndex(unsigned int i) const
{	
	if (i > 99)
	{
		std::cout << "Index cant be over 99, ma brain aint that big, brother ..." << std::endl;
		return "";
	}
	return (_ideas[i]);
}

