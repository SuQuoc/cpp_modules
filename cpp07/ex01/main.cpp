
# include "iter.hpp"
# include <string>

#define LINE    std::cout << "---------------------------" << std::endl;

void toUpper(std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i) {
        str.at(i) = std::toupper(str.at(i));
    }
}

int main( void ) 
{
	int arr[] = {10, 20, 30, 40};
	::print_arr<int>(arr, 4);
	::iter<int>(arr, 4, times2);
	::print_arr<int>(arr, 4);
	LINE;
	double d_arr[] = {1.5, 2.2, 3.3, 4.4};
	::print_arr<double>(d_arr, 4);
	::iter<double>(d_arr, 4, times2);
	::print_arr<double>(d_arr, 4);
	LINE;
	std::string str_arr[3] = {"This is", "an", "array of strings"};
	::print_arr<std::string>(str_arr, 3);
	::iter<std::string>(str_arr, 3, toUpper);
	::print_arr<std::string>(str_arr, 3);
	LINE;
}
