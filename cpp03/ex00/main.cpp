
#include "ClapTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

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
	serge.attack("Niki");

	hao.getStatus();
	serge.getStatus();

	std::cout << BLUE << "Testing copying:" << RESET << std::endl;
	ClapTrap copy1(serge);
	ClapTrap copy2("Noname");
	copy2 = serge;
	copy1.getStatus();
	copy2.getStatus();
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

	std::cout << BLUE << "Testing over-repairing:" << RESET << std::endl;
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
	//attack_test("hao", "serge");
	takeDamage_test("hao", "serge");
	//beRepaired_test("hao", "serge");
	//energy_test("hao");	
}