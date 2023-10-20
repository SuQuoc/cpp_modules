
# include "iter.hpp"
# include <string>

#define LINE    std::cout << "---------------------------" << std::endl;
/* class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

*/
template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
} 

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
	::iter<int>(arr, 4, ::times2<int>);
	::print_arr<int>(arr, 4);
	LINE;
	double d_arr[] = {1.5, 2.2, 3.3, 4.4};
	::print_arr<double>(d_arr, 4);
	::iter<double>(d_arr, 4, ::times2byAdding<double>);
	::print_arr<double>(d_arr, 4);
	LINE;
	std::string str_arr[3] = {"This is", "an", "array of strings"};
	::print_arr<std::string>(str_arr, 3);
	::iter<std::string>(str_arr, 3, ::toUpper);
	::print_arr<std::string>(str_arr, 3);
	LINE;
	std::string str_arr2[3] = {"This is", "an", "array of strings"};
	::print_arr<std::string>(str_arr, 3);
	::iter<std::string>(str_arr, 3, ::times2byAdding<std::string>);
	::print_arr<std::string>(str_arr, 3);
	LINE;
}
