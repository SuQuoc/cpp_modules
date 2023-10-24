
# include "Tests.hpp"
# include "Span.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void testFrameWork(void (*funcPTR)())
{
	if (funcPTR == NULL)
		std::cerr << RED << "Error: Invalid pointer" << std::endl << RESET;
	try
	{
		funcPTR();
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}

void subject(void)
{
	Span sp = Span(7);
	sp.addNumber(1);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(2);
	sp.addNumber(2);


	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void rangeTest(void)
{
	Span sp = Span(5);
	sp.addNumber(1);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(900);
}

void sizeZero_One_Two(void)
{
	Span sp = Span(2);
	sp.addNumber(1);
	sp.addNumber(10);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void addManyNum(void)
{
	Span sp(10);
	sp.addManyNumbers(9, 4);
	sp.printSpan();
	sp.addManyNumbers(2, 4);
	sp.printSpan();
}


void over10K(void)
{
	Span sp(1000000);
	sp.addManyNumbers(10000, 1);
	sp.addManyNumbers(10000, 4);
	sp.addManyNumbers(10000, 8);
	sp.addManyNumbers(10000, 12);
	sp.addManyNumbers(10000, 20);
	sp.addManyNumbers(10000, 50);
	sp.addManyNumbers(10000, 100);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

void negativeValues(void)
{

}
