
#include "ScavTrap.hpp"

//Canonical form
ScavTrap::ScavTrap (void)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap& src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap (void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

//Constructors
ScavTrap::ScavTrap (const std::string name)
: ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap with the name \"" << name << "\" constructed." << std::endl;
}
		

void ScavTrap::attack(const std::string& target)
{
	if (isAlive() && isCharged())
	{
		this->_energyPoints--;
    	std::cout << "ScavTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

//
void ScavTrap::guardGate()
{
	std::cout << "Im in gate keeper mode." << std::endl;
}