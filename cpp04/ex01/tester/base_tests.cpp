
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

void wrongSubject(void)
{
	coutTestName("wrongSubject");
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

}

void destructorTest(void)
{
	coutTestName("destructorTest");
	std::cout << YELLOW << 
	"💡 If the destructor in the base class isnt virtual, proper destruction (deleting) isnt given!" 
	<< RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	deleteAnimals(meta, j, i);
}

void typeTest(void)
{
	coutTestName("typeTest");
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	meta->setType("Hippo");
	j->setType("Giraffe");
	i->setType("Crocodile");
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
}
