
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void attack_test(std::string name1, std::string name2)
{
	ClapTrap hao(name1);
	ClapTrap serge(name2);
	hao.getStatus();
	serge.getStatus();


	hao.attack(serge.getName());
	hao.attack("Random name non ClapTrap object");
	serge.getStatus();
	hao.getStatus();

}

void takeDamage_test(std::string name1, std::string name2)
{
	ClapTrap hao(name1);
	ClapTrap serge(name2);

	hao.takeDamage(100);
	hao.takeDamage(100);
	hao.attack("Niki");
	hao.beRepaired(100);


	serge.takeDamage(2);
	serge.takeDamage(3);
	hao.getStatus();
	serge.getStatus();
}

void beRepaired_test(std::string name1, std::string name2)
{
	ClapTrap hao(name1);
	ClapTrap serge(name2);

	hao.takeDamage(2);
	hao.beRepaired(10);
	hao.getStatus();
	
	hao.takeDamage(0);
	hao.takeDamage(18);
	hao.beRepaired(10);
	hao.getStatus();

	std::cout << "Testing over-repairing:" << std::endl;
	serge.beRepaired(2147483647 *2U + 1U);
	serge.beRepaired(2147483647 *2U + 1U - 10);
	serge.beRepaired(1);
	serge.getStatus();
}

void energy_test(std::string name1)
{
	ClapTrap hao(name1);
	
	for (int i = 0; i < 9; i++)
		hao.attack("dummy");

	hao.takeDamage(0);
	hao.takeDamage(1);
	hao.getStatus();

	hao.attack("Jisoo");

	hao.attack("Jisoo");
	hao.takeDamage(1);
	hao.beRepaired(1);
}


int main()
{
	ScavTrap s1("Scavy");
	//s1.getStatus();
	//
	//s1.attack("target");
//
	//s1.guardGate();
//
	//s1.takeDamage(1);
	//s1.getStatus();
//
	//s1.beRepaired(2);
	//s1.getStatus();


	
	ScavTrap s2(s1);
	s2.getStatus();

	s2.takeDamage(200);
	s2.attack("dummy");
	s2.beRepaired(2);

	ScavTrap s0 ("Trapy");
	ScavTrap s3 ("lalalaalalal");
	s3 = s0;
	s3.getStatus();

	//for (int i = 0; i < 50; i++)
	//	s3.beRepaired(1);
	//s3.attack("SOMETHING");
	//s3.beRepaired(1);
}