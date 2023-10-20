
# include "Array.hpp"
# include <iostream>
# include <cstdlib>

#define LINE    std::cout << "---------------------------" << std::endl;

class Awesome
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

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}


void testFrameWork(void (*funcPTR)())
{
	if (funcPTR == NULL)
		std::cerr << RED << "Error: Invalid pointer" << std::endl << RESET;
	try
	{
		funcPTR();
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}

void deepCopyTest()
{
	unsigned int n = 5;

	Array<int> arr1(n);
	arr1.print();
	arr1.setAllTo(10);
	arr1[0] = 1;
	arr1.print();
	LINE;

	Array<int> arr2(arr1);
	arr2[0] = 2;
	arr2.print();
	arr1.print();
	LINE;

	Array<int> arr3(n);
	arr3.setAllTo(3);	
	arr3 = arr2;
	arr3[0] = 3;
	arr2.print();
	arr3.print();
}

void emptyArrTest()
{
	Array<int> arr;
	std::cout << arr[0] << std::endl;
}


void sizeTest()
{
	Array<int> arr(10);

	std::cout << "arr size: " << arr.size() << std::endl;
	arr[0] = 1;
	arr[9] = 2;
	arr.print();
	arr[-1] = 3;
	// arr[10] = 3;
}



void differentArrTypes(std::string requestedType)
{
	std::string dataTypes[] = {"string", "custom", "int", "float"};
	int index;

	for (unsigned long i = 0; i < dataTypes->size(); i++)
	{
		if (dataTypes[i] == requestedType)
			index = static_cast<int>(i);
	}
	Array<std::string> arr(10);
	Array<Awesome> arr1(10);
	Array<int> arr2(10);
	Array<float> arr3(10);
	switch (index)
	{
		case 0:
			arr.setAllTo("Ha");
			arr.print();
			break;
		case 1:
			arr1.print();
			break;
		case 2:
			arr2.setAllTo(10);
			arr2.print();
			break;
		case 3:
			arr3.setAllTo(5.5f);
			arr3.print();
			break;
		default:
			printMessage(std::cout, "Not supported data type", RED);
	}

}
#define MAX_VAL 5
int subject(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		tmp.print();
		test.print();
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main (int argc, char **argv)
{
	if (argc > 3 || argc == 1)
		return 1;
	std::string in = argv[1];
	
	if (argc == 3 && in == "0")
		differentArrTypes(argv[2]);
	else if (argc == 2)
	{
		if (in == "0")
			subject(1, NULL);
		if (in == "1")
			testFrameWork(emptyArrTest);
		else if (in == "2")
			testFrameWork(deepCopyTest);
		else if (in == "3")
			testFrameWork(sizeTest);
	}
}
