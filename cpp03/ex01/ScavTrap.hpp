
#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

class ScavTrap: public ClapTrap
{
	private: 
		ScavTrap (void);
		
	public:
		ScavTrap (const std::string name);
		ScavTrap (const ScavTrap& src);
		ScavTrap& operator = (const ScavTrap& rhs);
		~ScavTrap (void);

		void attack (const std::string& target);
		void guardGate();
};