
# include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error filename required." << std::endl;
		return 1;
	}
	if (argc != 2)
	{
		std::cout << "Error only 1 file allowed." << std::endl;
		return 1;
	}
	//i think this class makes more sense as a static class
	BitcoinExchange coinbase;
	coinbase.loadCSV_Database("data.csv");
	coinbase.calcInputFile(argv[1]);
	return 0;
}
