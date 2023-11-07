
#pragma once

#include <iostream>

class Brain
{

private: 
	std::string _ideas[100]; //would be cool to make this dynamic

public:
	Brain(void);
	Brain(const Brain& src);
	Brain& operator = (const Brain& rhs);
	~Brain(void);

	Brain (const std::string& type);

	void setIdeaAtIndex(const std::string& idea, unsigned int i);
	void setAllIdeas(const std::string& idea);

	std::string getIdeaAtIndex(unsigned int i) const;


	//std::string getType() const;
	//virtual void makeSound() const;
};