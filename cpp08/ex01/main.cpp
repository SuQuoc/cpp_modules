
# include "Span.hpp"
# include "Tests.hpp"

int main(int argc, char **argv)
{
	std::string in;
	if (argc != 2)
		return 1;
	char choice = argv[1][0];
	switch (choice)
	{
		case 's':
			testFrameWork(subject);
			break;
		case '0':
			testFrameWork(sizeZero_One_Two);
			break;
		case 'r':
			testFrameWork(rangeTest);
			break;
		case 'a':
			testFrameWork(addManyNum);
			break;
		case '1':
			testFrameWork(over10K);
			break;
		case 'n':
			testFrameWork(negativeValues);
			break;
		case 'o':
			testFrameWork(overIntMax);
			break;
		default:
			std::cout << "No test available." << std::endl;
	}
}
