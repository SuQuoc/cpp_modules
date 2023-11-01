
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

class BitcoinExchange
{
private:
	std::map<std::string, double> _exchangeRates;
	
	void calcBtcToValue(const std::string& date, double amount) const;
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
