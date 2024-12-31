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

    std::ifstream infile(inputFile);
    std::ofstream outfile(outputFile);

    replaceText(infile, outfile, str1, str2);
}

void replaceText(std::ifstream &infile, std::ofstream &outfile, std::string str1, std::string str2)
{
    std::string buffer;
    std::size_t position = -1;

    while (std::getline(infile, buffer))
    {
        position = buffer.find(str1);
        while (position != std::string::npos)
        {
            buffer.erase(position, str1.size());
            buffer.insert(position, str2);
            position = buffer.find(str1);
        }
        outfile << buffer;
        if (infile.peek() != EOF)
            outfile << '\n';
    }
}
