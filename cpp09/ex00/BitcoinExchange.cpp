
# include "BitcoinExchange.hpp"

std::pair<std::string, std::string> splitString(const std::string& str, char delimiter) 
{
    size_t pos = str.find(delimiter);

    if (pos == std::string::npos) 
	{
        // Delimiter not found, so the entire string is the first part.
        return std::make_pair(str, "");
    }

    std::string firstPart = str.substr(0, pos);
    std::string secondPart = str.substr(pos + 1);

    return std::make_pair(firstPart, secondPart);
}


BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	if (this == &src)
		return ;
	*this = src;
}
BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return *this;
	_exchangeRates = rhs._exchangeRates;
	return *this;
}

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
		std::cout << "Error: Invalid number in CSV file" << std::endl; 
		iss.clear();
		return ;
	}
	iss.clear();
}

int getInputData(std::ifstream& file, std::string& date, double& rate, char delim)
{
	std::istringstream iss;
	std::string line;
	std::pair<std::string, std::string> dateValuePair;

	getline(file, line, '\n');
	dateValuePair = splitString(line, delim);
	if (dateValuePair.second.empty())
	{
		std::cout << "Error: no delimiter found" << std::endl; 
		return 1;
	}
	if (dateValuePair.first.back() != ' ' || dateValuePair.second.front() != ' ')
	{
		std::cout << "Error: incorrect format (date | value)" << std::endl; 
		return 1;
	}
	dateValuePair.first.pop_back(); //removing the whitespace
	date = dateValuePair.first;
	iss.str(dateValuePair.second);
	iss >> rate;
	if (iss.fail() || !iss.eof())
	{
		std::cout << "Error: invalid number (number must end with a digit, be aware of whitespaces)" << std::endl; 
		iss.clear();
		return 1;
	}
	iss.clear();
	return 0;
}

// what happens with dupolicate dates? --> not handled, database wont be checked
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
		file.close();
		return ;
	}
	while (file.good())
	{
		getCSVData(file, date, rate, CSV_DELIM);
		_exchangeRates.insert(std::pair<std::string, double>(date, rate));
	}
	file.close();
}

bool isValidDate(const std::string& dateString) 
{
    // Date string must be exactly 10 characters long (YYYY-MM-DD).
    if (dateString.length() != 10 || dateString[4] != '-' || dateString[7] != '-')
	{
        return (false);
	}
	
	int year = atoi(dateString.substr(0, 4).c_str());
	int month = atoi(dateString.substr(5, 2).c_str());
	int day = atoi(dateString.substr(8, 2).c_str());
	
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) 
	{
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

void BitcoinExchange::calcBtcToValue(const std::string& date, double amount) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.begin() && date != it->first)
	{
		std::cout << "Error: Btc was invented on 3. Januar 2009 (wikipedia), even database wrong?? ¯\\_(ツ)_/¯ " << std::endl;
		return;
	}
	if (it == _exchangeRates.end() || date != it->first)
		it--;
	std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;
}

void BitcoinExchange::calcInputFile(const std::string& filename) const
{	
	std::ifstream file; 
	std::string inputHeader;
	std::string date;
	double amount = 0; 

	if (_exchangeRates.empty())
	{
		std::cerr << "Error: database must not be empty before calculating btc values." << std::endl;
		return ;
	}

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
		file.close();
		return ;
	}
	while (file.good())
	{
		if (getInputData(file, date, amount, INPUT_FILE_DELIM) == 1)
			continue;
		else if (!isValidDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (amount < LOWER_LIM)
			std::cout << "Error: not a positive number" << std::endl;
		else if (amount > UPPER_LIM)
			std::cout << "Error: too large a number" << std::endl;
		else
			calcBtcToValue(date, amount);
	}
	file.close();
}
