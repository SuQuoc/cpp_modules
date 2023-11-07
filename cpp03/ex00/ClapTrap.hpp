
#pragma once

#include <iostream>
#include <climits>

class ClapTrap
{
	private: 
		ClapTrap (void);
		std::string 			_name;
		unsigned int 			_hitPoints;
		unsigned int 			_energyPoints;
		unsigned int 			_attackDamage;

		bool isAlive(void);
		bool isCharged(void);

	public:
		ClapTrap (const std::string name);
		ClapTrap (const ClapTrap& src);
		ClapTrap& operator = (const ClapTrap& rhs);
		~ClapTrap (void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void getStatus(void) const;
		std::string getName(void) const;
};