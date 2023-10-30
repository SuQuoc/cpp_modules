
# include "BitcoinExchange.hpp"
# include "helper.hpp"

int main(int argc, char **argv)
{
	std::fstream inputFile;
	if (argc == 1 || !fileOpenAble(argv[1], inputFile))
	{
		std::cerr << "Error could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange coinbase;
	coinbase.loadCSV_Database("data.csv");
	coinbase.calcBtcToValue(argv[1]);
	
	return 0;
}
