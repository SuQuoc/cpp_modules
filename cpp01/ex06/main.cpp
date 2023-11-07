
#include "main.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Please pass in a level and only!" << std::endl;
        return (1);
    }

    Harl thefirst;

    for (int i = 0; i < 4; i++) 
    {

    }

    switch (i)
    {
        case 0:
            std::cout << "Im debuging" << std::endl;
            //break;
        case 2:
            std::cout << "I need info" << std::endl;
            //break;
        case 3:
            std::cout << "I need info" << std::endl;
            //break;
        case 4:
            std::cout << "I need info" << std::endl;
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }




    std::cout << std::endl << "> What happens with a wrong level:" << std::endl;
    thefirst.complain("Error");
    thefirst.complain("errorwarning");
    thefirst.complain("Error\n");
    thefirst.complain("dsadasdasas");
    thefirst.complain("");

    //thefirst.debug();
    return (0);
}
