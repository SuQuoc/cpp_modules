
#include "../main.hpp"

void deleteAnimals(const Animal *p1, const Animal *p2, const Animal *p3)
{
	delete p1;
	delete p2;
	delete p3;
}

void coutTestName(std::string test)
{
	std::cout << B_BLUE << test << RESET << std::endl;
}