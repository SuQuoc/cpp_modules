
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "address of string: "<< &str << std::endl;    
    std::cout << "address of string: "<< stringPTR << std::endl;    
    std::cout << "address of string: "<< &stringREF << std::endl;
    
    std::cout << "actual string: "<< str << std::endl;    
    std::cout << "actual string: "<< *stringPTR << std::endl;    
    std::cout << "actual string: "<< stringREF << std::endl;

    return (0);
}