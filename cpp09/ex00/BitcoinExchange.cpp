
# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}



void getCSVData(std::ifstream& file, std::string& date, double& rate, char delim)
{
	std::istringstream iss;
	std::string temp;

	getline(file, date, delim);
	getline(file, temp, '\n');
	iss.str(temp);
	iss >> rate;
	if (iss.fail())
	{
		//2001-42-42 
		//
		std::cout << "Error: Invalid number" << std::endl; 
		iss.clear();
		return ;
	}
	iss.clear();
}

void getInputData(std::ifstream& file, std::string& date, double& rate, char delim)
{
	std::istringstream iss;
	std::string temp;

	getline(file, date, delim);
	getline(file, temp, '\n');
	iss.str(temp);
	iss >> rate;
	if (iss.fail())
	{
		//2001-42-42 
		//
		std::cout << "Error: Invalid number" << std::endl; 
		iss.clear();
		return ;
	}
	iss.clear();
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
		getData(file, date, rate, CSV_DELIM);
		_exchangeRates.insert(std::pair<std::string, double>(date, rate));
	}
	file.close();
	// printMap(_exchangeRates);
}



// doesnt check for leap years or days with 31 or 30 days or february
bool isValidDateIHATECTIME(const std::string& dateString)
{
	// Date string must be exactly 10 characters long (YYYY-MM-DD).
    if (dateString.length() != 11 || dateString[4] != '-' || dateString[7] != '-' || dateString[10] != ' ')
	{
        return (false);
	}
	std::tm Date = {};
	Date.tm_year = atoi(dateString.substr(0, 4).c_str()) - 1900; //year since 1900, see c library
	Date.tm_mon = atoi(dateString.substr(5, 2).c_str()) - 1; //month since january
	Date.tm_mday = atoi(dateString.substr(8, 2).c_str());

	std::cout << "Date: ";
    std::cout << std::put_time(&Date, "%Y-%m-%d") << std::endl;
	// std::cout << "year: " << Date.tm_year << "month: " << Date.tm_mon << "day: " << Date.tm_mday << std::endl;
	

	std::cout << "SHIT: " << std::asctime(&Date) << std::endl;

	
    // const std::tm time = std::mktime(&Date);

	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d ", &Date);
    return (true);
}

bool isValidDate(const std::string& dateString) 
{
    // Date string must be exactly 10 characters long (YYYY-MM-DD).
    if (dateString.length() != 11 || dateString[4] != '-' || dateString[7] != '-')
	{
		std::cout << "SHIT: " << std::endl;
        return (false);
	}
	
	int year = atoi(dateString.substr(0, 4).c_str());
	int month = atoi(dateString.substr(5, 2).c_str());
	int day = atoi(dateString.substr(8, 2).c_str());
	
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;  // Basic range checks
    }
    
    if (month == 2)
	{
        // Check for February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
            return day <= 29; // Leap year
		else
            return day <= 28; // Non-leap year
    } 
	else if (month == 4 || month == 6 || month == 9 || month == 11) 
	{
        // Months with 30 days
        return day <= 30;
    } 
	else
	{
        // Months with 31 days
        return day <= 31; 
    }
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
		getData(file, date, amount, INPUT_FILE_DELIM);
		if (date.find('\n') != std::string::npos)
			std::cout << "Error: invalid format" << std::endl;
		else if (!isValidDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (amount < 0)
			std::cout << "Error: not a positive number" << std::endl;
		else if (amount > std::numeric_limits<int>::max())
			std::cout << "Error: too large a number" << std::endl;
		else
			std::cout << date << " => " << amount << " = " << "CALC VBALUE" << std::endl;
	}
	file.close();
}
