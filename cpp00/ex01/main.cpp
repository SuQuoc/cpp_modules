
#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string cmd;
    while (cmd != "EXIT")
    {
        if(!std::cin.eof())
        {
            std::cout << "Enter command: ";
            std::getline(std::cin, cmd);
        }
        else 
        {
            std::cout << std::endl;
            return 0;
        }
        if (cmd.compare("ADD") == 0)
            book.add();
        else if (cmd.compare("SEARCH") == 0)
            book.search();
        else if (cmd != "EXIT")
            std::cout << "Wrong command, please try again." << std::endl;
    }
    return (0);
}