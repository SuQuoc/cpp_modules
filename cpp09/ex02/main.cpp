
# include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		return 1;

	std::cout << "Before:";
	for (int i = 1; argv[i] != nullptr; ++i)
		std::cout << " " << argv[i];
	std::cout << std::endl;

	std::cout << "After:";
	//Baustelle
	std::cout << std::endl;
	
	
	PmergeMe p;
	p.sort_Vec(argv);
	return 0;
}
