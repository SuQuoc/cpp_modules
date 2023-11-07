
#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private: 
		FragTrap (void);
		
	public:
		FragTrap (const std::string name);
		FragTrap (const FragTrap& src);
		FragTrap& operator = (const FragTrap& rhs);
		~FragTrap (void);

		void highFiveGuys(void);
};