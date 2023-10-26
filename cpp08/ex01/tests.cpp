
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
	sp.addNumber(200);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	sp.printSpan();
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

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

}

void addManyNum(void)
{
	int len = 10;
	Span sp(len);
	std::vector<int> container;
	// std::list<int> container;

	srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        int randomValue = rand() % 100;
        container.push_back(randomValue);
    }

	sp.addManyNumbers(container.begin(), container.end());
	// sp.addManyNumbers<std::vector<int>::iterator>(container.begin(), container.begin() + 7);
	
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	sp.printSpan();
}


void over10K(void)
{
	Span sp(TEST_SIZE);
	std::vector<int> container;

	srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < TEST_SIZE; ++i) {
        int randomValue = rand() % 100;
        container.push_back(randomValue);
    }

	sp.addManyNumbers<std::vector<int>::iterator>(container.begin(), container.end());
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

void negativeValues(void)
{
	Span sp(100000);
	sp.addNumber(100);
	sp.addNumber(-20);
	sp.addNumber(-10);
	sp.addNumber(20);
	sp.addNumber(-70);
	sp.addNumber(40);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

void overIntMax(void)
{
	Span sp(100);
	sp.addNumber(2147483647);
	sp.addNumber(-2147483648);
	sp.addNumber(0);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}
