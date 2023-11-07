
#include "FragTrap.hpp"

//Canonical form
FragTrap::FragTrap (void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap (const FragTrap& src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator = (const FragTrap& rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

FragTrap::~FragTrap (void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

//Constructors
FragTrap::FragTrap (const std::string name)
: ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap with the name \"" << name << "\" constructed." << std::endl;
}
		

//
void FragTrap::highFiveGuys(void)
{
	std::cout << "Positive high fives request!" << std::endl;
}