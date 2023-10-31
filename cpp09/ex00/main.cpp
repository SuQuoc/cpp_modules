
# include "BitcoinExchange.hpp"
# include "helper.hpp"

int main(int argc, char **argv)
{
	std::fstream inputFile;
	std::string input = argv[1];
	if (argc == 1)
	{
		std::cerr << "Error could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange coinbase;
	coinbase.loadCSV_Database("data.csv");
	coinbase.calcInputFile(input);
	coinbase.loadCSV_Database("data2.csv");
	coinbase.calcInputFile(input);

	return 0;
}
