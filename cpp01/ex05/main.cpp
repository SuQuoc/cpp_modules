
#include "main.hpp"


int main(void)
{
    Harl thefirst;

    thefirst.complain("debug");
    thefirst.complain("info");
    thefirst.complain("warning");
    thefirst.complain("error");

    std::cout << std::endl << "> Just to make sure nothing sus happens with the order:" << std::endl;
    thefirst.complain("error");
    std::cout << std::endl;
    thefirst.complain("warning");
    std::cout << std::endl;
    thefirst.complain("info");
    std::cout << std::endl;
    thefirst.complain("debug");
    std::cout << std::endl;

    std::cout << std::endl << "> What happens with a wrong level:" << std::endl;
    thefirst.complain("Error");
    thefirst.complain("errorwarning");
    thefirst.complain("Error\n");
    thefirst.complain("dsadasdasas");
    thefirst.complain("");

    //thefirst.debug();
    return (0);
}

