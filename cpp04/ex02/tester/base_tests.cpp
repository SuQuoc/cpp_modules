
#include "../main.hpp"

void subject(void)
{
	coutTestName("subject");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
	return ;
}

void subject_arr(int n)
{
	Animal* arr[n]; 

	int i;
	for(i = 0; i < n / 2; i++)
	{
		arr[i] = new Dog();
		LINE;
	}
	for(;i < n; i++)
	{
		arr[i] = new Cat();
		//arr[i]->makeSound();
		//dynamic_cast<Cat*>(arr[i])->setAllIdeas("aishjakas");
		LINE;
	}
	for (i = 0; i < n; i++)
	{
		delete arr[i];
		LINE;
	}
}