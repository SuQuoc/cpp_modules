
#pragma once

#include "WrongAnimal.hpp"
#include "Brain.hpp"


class WrongCat: public WrongAnimal
{
private: 
	Brain*	_brainPTR;

public:
	WrongCat(void);
	WrongCat(const WrongCat& src);
	WrongCat& operator = (const WrongCat& rhs);
	~WrongCat(void);

	void setIdeaAtIndex(const std::string& idea, unsigned int i);
	void setAllIdeas(const std::string& idea);

	std::string getIdeaAtIndex(unsigned int i) const;

	void makeSound() const; //not sure if they want that
	void coutIdeaAtIndex(unsigned int i) const;
};