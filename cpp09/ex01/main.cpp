
# include "RPN.hpp"

int main(int argc, char **argv)
{
	std::string input;
	if (argc != 2 || argv[1] == NULL)
	{
		std::cout << "Error: invalid argument count" << std::endl;
		std::cout << "Example: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return 1;
	}
	input = argv[1];
	RPN poland;
	try
	{
		std::cout << poland.calcPolNotation(input) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
