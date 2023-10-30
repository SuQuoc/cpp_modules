
# include "helper.hpp"

bool fileOpenAble(std::string filename, std::fstream& file)
{
	file.open(filename.c_str());
    if (file.is_open()) 
	{
        std::cout << "File is open." << std::endl;
        return true;
    }
    return false;
}
