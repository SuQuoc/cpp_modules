
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{
}

Base * generate(void)
{

	std::srand(std::time(NULL));
	
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "Not A,B or C object" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& aREF = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)aREF;
		return ;
	}
	catch (std::exception& e) {}
	try 
	{
		B& bREF = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)bREF;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		C& cREF = dynamic_cast<C&>(p);
		(void)cREF;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "Not A,B or C object" << std::endl;
}
