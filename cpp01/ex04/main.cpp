
#include "main.hpp"

static void rtfm(void)
{
    std::cout << "Neccessary parameters:" << std::endl;
    std::cout << "1. Name of a file" << std::endl;
    std::cout << "2. The string you want to change" << std::endl;
    std::cout << "3. The string it should be replaced with" << std::endl;
}

static void replace_s1_w_s2(std::string *str, std::string& s1, std::string& s2)
{    
    size_t s1_len = s1.length();
    size_t s2_len = s2.length();

    if (s1 == s2 || s1 == "") 
        return ; 
    for (size_t pos = (*str).find(s1); pos != std::string::npos; pos = (*str).find(s1, pos))
    {   
        (*str).erase(pos, s1_len);
        (*str).insert((std::string::size_type)(pos), s2);
        pos += s2_len;
    }
}

static std::string get_file_str(std::ifstream& file)
{
    std::stringstream buffer;
    std::string str;

    buffer << file.rdbuf();
    str = buffer.str();
    return (str);
}

// yes i allow text.replace as input file
int main(int argc, char **argv)
{
    if (argc != 4)
        return (rtfm(), 0);
    
    std::string filename = argv[1];
    std::string filecontent;
    std::string s1 = argv[2]; 
    std::string s2 = argv[3];
    std::string newfile = filename + ".replace";
    
    std::ifstream infile (filename.c_str());
    if (!infile.is_open())
        return (std::cerr << "Error: Failed to open the file" << std::endl, 1);
    
    std::ofstream outfile (newfile.c_str());
    if (!outfile.is_open())
        return (std::cerr << "Error: Failed to create filename.replace" << std::endl, 1);
    
    filecontent = get_file_str(infile);
    infile.close();
    
    replace_s1_w_s2(&filecontent, s1, s2);
    outfile << filecontent;
    outfile.close();
    return (0);
}
