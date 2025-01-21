#include "replace.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Format: ./program <filename> string1 string2" << std::endl;
        return 1;
    }

    std::string str1 = argv[2];
    std::string str2 = argv[3];
    std::string inputFile = argv[1];
    std::string outputFile = inputFile + ".replace";

    std::ifstream infile(inputFile.c_str()); // What happens here is the file doesn't exist
    if (!infile)
    {
        std::cerr << "Error: Could not open file " << inputFile << std::endl;
        return 1;
    }
    std::ofstream outfile(outputFile.c_str());
    replaceText(infile, outfile, str1, str2);
}
