
# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}



void getData(std::ifstream& file, std::string& date, double& rate)
{
	std::istringstream iss;
	std::string temp;

	getline(file, date, ',');
	getline(file, temp, '\n');
	iss.str(temp);
	iss >> rate;
	iss.clear();
	if (iss.fail())
	{
		std::cerr << "Invalid number" << std::endl;
		return ;
	}
}

// what happens with dupolicate dates? --> not handled database wont be checked
// first occurence will be taken
void BitcoinExchange::loadCSV_Database(const std::string& filename)
{
	std::ifstream file; 
	std::string csvHeader;
	std::string date;
	double rate;

	if (!_exchangeRates.empty())
	{
		std::cout << "Warning: btc database was overwritten" << std::endl;
		clearMap(_exchangeRates);
	}

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Failed to open CSV-file" << std::endl;
		return ;
	}

	getline(file, csvHeader, '\n');
	if (csvHeader != CSV_HEADER)
	{
		std::cerr << "Missing or invalid header in CSV-file" << std::endl;
		return ;
	}
	while (file.good())
	{
		getData(file, date, rate);
		_exchangeRates.insert(std::pair<std::string, double>(date, rate));
	}
	file.close();
	// printMap(_exchangeRates);
}



void BitcoinExchange::calcBtcToValue(const std::string& filename) const
{	
	std::ifstream file; 
	std::string inputHeader;
	std::string date;
	double amount; 

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error could not open file." << std::endl;
		return ;
	}

	getline(file, inputHeader, '\n');
	if (inputHeader != INPUT_HEADER)
	{
		std::cerr << "Missing or invalid header in input file" << std::endl;
		return ;
	}
	while (file.good())
	{
		getData(file, date, amount);
		std::cout << date << " => " << amount << " = " << "CALC VBALUE" << std::endl;
	}



	file.close();

}
