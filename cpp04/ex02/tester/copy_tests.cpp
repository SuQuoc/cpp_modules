
#include "../main.hpp"
/// @brief 
void deepCopyTest()
{
	int i = 10;

	Cat c1;
	c1.setAllIdeas("I want fish!");
	c1.coutIdeaAtIndex(i);
	LINE;
	Cat c2(c1);
	c2.coutIdeaAtIndex(i);
	c2.setAllIdeas("I want milk!");
	c2.coutIdeaAtIndex(i);
	c1.coutIdeaAtIndex(i);
	LINE;
	Cat c3;
	c3.setAllIdeas("I want mouses!");
	c3.coutIdeaAtIndex(i);
	c2.coutIdeaAtIndex(i);
	c3 = c2;
	c3.coutIdeaAtIndex(i);
	c2.coutIdeaAtIndex(i);
}

void deepCopyTestWrong()
{
	int i = 10;

	WrongCat c1;
	c1.setAllIdeas("I want fish!");
	c1.coutIdeaAtIndex(i);
	LINE;
	WrongCat c2(c1);
	c2.coutIdeaAtIndex(i);
	c2.setAllIdeas("I want milk!");
	c2.coutIdeaAtIndex(i);
	c1.coutIdeaAtIndex(i);
	LINE;
	WrongCat c3;
	c3.setAllIdeas("I want mouses!");
	c3.coutIdeaAtIndex(i);
	c2.coutIdeaAtIndex(i);
	c3 = c2;
	c3.coutIdeaAtIndex(i);
	c2.coutIdeaAtIndex(i);
}

/* void copyTest(void)
{
	coutTestName("copyTest");
	coutTestName("- base Class copy cons. and assign. test");
	
	Animal an1("Monkey");
	Animal an2(an1);
	Animal an3;
	an3 = an1;
	
	std::cout << an1.getType() << "!" << std::endl;
	std::cout << an2.getType() << "!" << std::endl;
	std::cout << an3.getType() << "!" << std::endl;
	
	an1.setType("Baboon");
	an2.setType("Gorilla");
	std::cout << an1.getType() << "!" << std::endl;
	std::cout << an2.getType() << "!" << std::endl;
	std::cout << an3.getType() << "!" << std::endl;

	derivedClassCopyConsTest();
	derivedClassCopyAssignTest();
}

void derivedClassCopyConsTest(void)
{
	//Copy constructor
	coutTestName("- derivedClassCopyConsTest");
	Cat c1;
	Cat c2;
	Animal an1(c1);
	//Cat c2(an2);
	//doesnt work since an Animal (Class) is not neccesarrily a cat (Class)
	std::cout << c1.getType() << "!" << std::endl;
	std::cout << c2.getType() << "!" << std::endl;
	std::cout << an1.getType() << "!" << std::endl;

	c1.setType("Siam Cat");
	an1.setType("Animal Cat");

	std::cout << c1.getType() << "!" << std::endl;
	std::cout << c2.getType() << "!" << std::endl;
	std::cout << an1.getType() << "!" << std::endl;
}

void derivedClassCopyAssignTest(void)
{
	//Copy assignment operator
	coutTestName("- derivedClassCopyAssignTest");
	Dog d1;
	Dog d2;

	d2 = d1;
	std::cout << d1.getType() << "!" << std::endl;
	std::cout << d2.getType() << "!" << std::endl;
	d1.setType("Werewolf");
	std::cout << d1.getType() << "!" << std::endl;
	std::cout << d2.getType() << "!" << std::endl;

	Animal an5;
	an5 = d1;
	std::cout << an5.getType() << "!" << std::endl;
} */