
#pragma once

#include <iostream>
#include <climits>

class ClapTrap
{
	protected: //
		ClapTrap (void);
		typedef unsigned int 	uint_t;//
		std::string 			_name;
		uint_t 			_hitPoints;
		uint_t 			_energyPoints;
		uint_t 			_attackDamage;

		bool isAlive(void);
		bool isCharged(void);

	public:
		ClapTrap (const std::string name);
		ClapTrap (const std::string name, uint_t hp, uint_t energy, uint_t ad);//
		ClapTrap (const ClapTrap& src);
		ClapTrap& operator = (const ClapTrap& rhs);
		virtual ~ClapTrap (void);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void getStatus(void) const;
		std::string getName(void) const;
};