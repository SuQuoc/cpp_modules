
# include "BitcoinExchange.hpp"
#include <stdlib.h> 

bool isOnlyWhitespace(const std::string& str) 
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) 
	{
       	if (!std::isspace(static_cast<unsigned char>(*it))) 
	   	{
            return false; // Found a non-whitespace character
        }
    }
    return true; // All characters are whitespaces or the string is empty
}

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

//Canonical form______________________________________________________________________
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

//member functions_________________________________________________________________
// what happens with dupolicate dates? --> not handled, database wont be checked
// first occurence will be taken
void BitcoinExchange::loadCSV_Database(const std::string& filename)
{
	std::ifstream file; 
	std::string csvHeader;
	

	if (!_exchangeRates.empty())
	{
		std::cout << "Warning: btc database was overwritten" << std::endl;
		clearMap(_exchangeRates);
	}
	file.open(filename.c_str());
	if (!file.is_open())
	{
		printErrorByCode(OPEN_CSV_ERR);
		return ;
	}

	getline(file, csvHeader, '\n');
	if (csvHeader != CSV_HEADER)
	{
		printErrorByCode(CSV_HDR_ERR);
		file.close();
		return ;
	}
	while (file.good())
	{
		getCSVData(file, CSV_DELIM);
	}
	file.close();
}

void BitcoinExchange::getCSVData(std::ifstream& file, char delim)
{
	std::istringstream iss;
	std::string temp;
	std::string date;
	double rate;

	getline(file, date, delim);
	if (date.empty())
		return ;
	getline(file, temp, '\n');
	iss.str(temp);
	iss >> rate;
	if (iss.fail())
	{
		printErrorByCode(CSV_DATA_ERR);
		iss.clear();
		return ;
	}
	iss.clear();
	_exchangeRates.insert(std::pair<std::string, double>(date, rate));
}

//Input file________________________________________________________________
void BitcoinExchange::calcInputFile(const std::string& filename) const
{	
	std::ifstream file; 
	std::string inputHeader;
	std::string date;
	double amount = 0; 

	if (_exchangeRates.empty())
	{
		printErrorByCode(EMPTY_DATA_ERR);
		return ;
	}

	file.open(filename.c_str());
	if (!file.is_open())
	{
		printErrorByCode(OPEN_INP_ERR);
		return ;
	}

	getline(file, inputHeader, '\n');
	if (inputHeader != INPUT_HEADER)
	{
		printErrorByCode(INP_HDR_ERR);
		file.close();
		return ;
	}
	while (file.good())
	{
		if (readInputLine(file, date, amount, INPUT_FILE_DELIM) == 1)
			continue;
		else if (!isValidDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (amount < LOWER_LIM)
			printErrorByCode(LOW_LIM_ERR);
		else if (amount > UPPER_LIM)
			printErrorByCode(UP_LIM_ERR);
		else
			calcBtcToValue(date, amount);
	}
	file.close();
}

//at the end of the date as well as the beginning of the value must be a space
int BitcoinExchange::readInputLine(std::ifstream& file, std::string& date, double& amount, char delim) const
{
	std::istringstream iss;
	std::string line;
	std::pair<std::string, std::string> dateValuePair;

	getline(file, line, '\n');
	if (line.empty() || isOnlyWhitespace(line))
		return 1;
	if (line.find(" | ") == std::string::npos 
		|| line.find_first_not_of("0123456789.- |") != std::string::npos
		|| std::count(line.begin(), line.end(), ' ') != 2)
	{
		printErrorByCode(FORMAT_ERR);
		return 1;
	}
	dateValuePair = splitString(line, delim);
	if (dateValuePair.second.empty())
	{
		printErrorByCode(INP_VALUE_ERR);
		return 1;
	}
	if (dateValuePair.first.size() == 11)
		dateValuePair.first.resize(10); //removing the space at end of date
	date = dateValuePair.first;
	iss.str(dateValuePair.second);
	iss >> amount;
	if (iss.fail() || !iss.eof())
	{
		printErrorByCode(INP_VALUE_ERR);
		iss.clear();
		return 1;
	}
	iss.clear();
	return 0;
}

void BitcoinExchange::calcBtcToValue(const std::string& date, double amount) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.begin() && date != it->first)
	{
		printErrorByCode(BTC_BEGIN_ERR);
		return;
	}
	if (it == _exchangeRates.end() || date != it->first)
		it--;
	std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;
}

void BitcoinExchange::printErrorByCode(int errorCode) const
{
	std::map<std::string, double>::const_iterator it;
	switch(errorCode)
	{
		case OPEN_CSV_ERR:
			std::cerr << "Error: Failed to open CSV-file." << std::endl;
			break;
		case CSV_HDR_ERR:
			std::cerr << "Error: Missing or invalid header in CSV-file." << std::endl;
			break;
		case CSV_DATA_ERR:
			std::cout << "Error: Invalid number in CSV file." << std::endl;
			break;
		case EMPTY_DATA_ERR:
			std::cerr << "Error: database must not be empty before calculating btc values." << std::endl;
			break;
		case OPEN_INP_ERR:
			std::cerr << "Error could not open file." << std::endl;
			break;
		case INP_HDR_ERR:
			std::cerr << "Missing or invalid header in input file." << std::endl;
			break;
		case UP_LIM_ERR:
			std::cout << "Error: too large a number." << std::endl;
			break;
		case LOW_LIM_ERR:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case FORMAT_ERR:
			std::cout << "Error: incorrect format (date | value)." << std::endl; 
			break;
		case INP_VALUE_ERR:
			std::cout << "Error: invalid number (number must end with a digit, be aware of whitespaces)." << std::endl;
			break;
		case BTC_BEGIN_ERR:
			it = _exchangeRates.begin();
			std::cout << "Error: No fitting date found according to database (earliest entry " << it->first << ")" << std::endl;
			break;
		default:
			std::cout << "Invalid error code passed." << std::endl;
	}
}
