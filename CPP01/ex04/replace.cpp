#include "replace.hpp"
#include <iostream>
#include <string>
#include <fstream>

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
