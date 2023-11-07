
# pragma once

# include <iostream>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <fstream>
# include <string>
# include <map>
# include <ctime>
# include <limits>
# include <iomanip>

# define CSV_HEADER			"date,exchange_rate"
# define INPUT_HEADER 		"date | value"
# define INPUT_FILE_DELIM 	'|'
# define CSV_DELIM 			','
# define UPPER_LIM 			1000
# define LOWER_LIM 			0

//Errors
# define OPEN_CSV_ERR 			2
# define CSV_HDR_ERR 			3
# define CSV_DATA_ERR 			4
# define EMPTY_DATA_ERR 		5
# define OPEN_INP_ERR 			6
# define INP_HDR_ERR 			7
# define DATE_ERR 				8
# define UP_LIM_ERR 			9
# define LOW_LIM_ERR 			10
# define FORMAT_ERR 			11
# define INP_VALUE_ERR 			12
# define BTC_BEGIN_ERR 			13



class BitcoinExchange
{
private:
	std::map<std::string, double> _exchangeRates;
	
	void calcBtcToValue(const std::string& date, double amount) const;
	void getCSVData(std::ifstream& file, std::string& date, double& rate, char delim);
	int readInputLine(std::ifstream& file, std::string& date, double& rate, char delim) const;
	
	void printErrorByCode(int errorCode) const;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator = (const BitcoinExchange& rhs);

	void loadCSV_Database(const std::string& filename);
	void calcInputFile(const std::string& filename) const;
};



template <typename Key, typename Value>
void printMap(const std::map<Key, Value>& myMap)
{
    for (typename std::map<Key, Value>::const_iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

template <typename Key, typename Value>
void clearMap(std::map<Key, Value>& myMap) 
{
    while (!myMap.empty()) 
	{
        typename std::map<Key, Value>::iterator it = myMap.begin();
        myMap.erase(it);
    }
}
