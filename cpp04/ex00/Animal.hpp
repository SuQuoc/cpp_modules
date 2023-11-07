
#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

private: 


public:
	Animal(void);
	Animal(const Animal& src);
	Animal& operator = (const Animal& rhs);
	virtual ~Animal(void);

	Animal (const std::string& type);

	void setType(const std::string& type); //eig will ich das nicht

	std::string getType() const;
	virtual void makeSound() const;

};