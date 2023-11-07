
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Dog: public Animal
{
private: 
	Brain*	_brainPTR;

public:
	Dog(void);
	Dog(const Dog& src);
	Dog& operator = (const Dog& rhs);
	~Dog(void);

	void setIdeaAtIndex(const std::string& idea, unsigned int i);
	void setAllIdeas(const std::string& idea);

	std::string getIdeaAtIndex(unsigned int i) const;

	void makeSound() const;
	void coutIdeaAtIndex(unsigned int i) const;
};