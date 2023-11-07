
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

void energy_and_hp_test(std::string name1)
{
	FragTrap hao(name1);
	
	for (int i = 0; i < 100; i++)
		hao.attack("dummy");

	hao.attack("Jisoo");
	hao.beRepaired(100);
	hao.takeDamage(50);
	hao.getStatus();

	hao.takeDamage(100);
	hao.getStatus();
}

void basic_functionality(void)
{
	FragTrap s1("Fragy");
	s1.getStatus();
	s1.attack("target");
	s1.beRepaired(2);
	s1.takeDamage(1);
	s1.highFiveGuys();
	s1.getStatus();

	//s1.guardGate();
	//FragTrap s2;
}

void copy_functionality(void)
{
	FragTrap f1("Fragy");
	FragTrap f2(f1);
	f2.getStatus();
	
	FragTrap f3 ("FragyTrapy");
	f2 = f3;
	f2.getStatus();

	ClapTrap c1 (f1);
	c1.getStatus();
}
int main()
{
	basic_functionality();
	copy_functionality();
	energy_and_hp_test("hao");
}