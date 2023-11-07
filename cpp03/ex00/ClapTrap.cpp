
#include "ClapTrap.hpp"

//Canonical form
ClapTrap::ClapTrap (void)
{
    std::cout << "Default constructor called" << std::endl;

}

ClapTrap::ClapTrap (const ClapTrap& src)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap (void)
{
    std::cout << "Destructor called" << std::endl;
}

//Constructors
ClapTrap::ClapTrap (const std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap with the name \"" << name << "\" constructed." << std::endl;
}
		

void ClapTrap::attack(const std::string& target)
{
	if (isAlive() && isCharged())
	{
		this->_energyPoints--;
    	std::cout << "ClapTrap " << this->_name << " attacks " << target
		 			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isAlive())
	{
    	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage." << std::endl;
		if (this->_hitPoints > amount)
			this->_hitPoints -= amount;
		else 
			this->_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!isAlive() || !isCharged())
		return ;
	if (this->_hitPoints == UINT_MAX)
	{
		std::cout << "ClapTrap " << this->_name << " is at max unsigned int, cant over-repair" << std::endl; 
		return ;
	}
	if (static_cast<unsigned long>(amount) + this->_hitPoints > static_cast<unsigned long>UINT_MAX)
	{
		std::cout << "ClapTrap " << this->_name << " cant repair over max unsigned int" << std::endl;
		return ;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name 
					<< " repairs itself, healing for " << amount
					<< " hitpoints." << std::endl;
		this->_hitPoints += amount;
	}
}

//My helper functions
bool ClapTrap::isAlive(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "No hp left, let me rest in peace..." << std::endl;
		return false;
	}
	return true;
}

bool ClapTrap::isCharged(void)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "No energy left..." << std::endl;
		return false;
	}
	return true;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

void ClapTrap::getStatus(void) const
{
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "STATUS CHECK ⚠️⚠️⚠️" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hp: " << this->_hitPoints << std::endl;
	std::cout << "Energy: " << this->_energyPoints << std::endl;
	std::cout << "Attack damage: " << this->_attackDamage << std::endl;
	std::cout << "--------------------------------------" << std::endl << std::endl;
}