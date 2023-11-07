
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Cat: public Animal
{
private: 
	Brain*	_brainPTR;

public:
	Cat(void);
	Cat(const Cat& src);
	Cat& operator = (const Cat& rhs);
	~Cat(void);

	void setIdeaAtIndex(const std::string& idea, unsigned int i);
	void setAllIdeas(const std::string& idea);

	std::string getIdeaAtIndex(unsigned int i) const;

	void makeSound() const;
	void coutIdeaAtIndex(unsigned int i) const;
};