#include "main.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed filename s1 s2" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}
	std::string s2 = argv[3];

	std::ifstream	input(filename.c_str());
	if (!input.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}

	std::ofstream	output((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << "Error: could not create output file" << std::endl;
		input.close();
		return 1;
	}

	std::string line;
	while (std::getline(input, line))
	{
		 size_t pos = 0;
		 while ((pos = line.find(s1, pos)) != std::string::npos)
		 {
			 line.erase(pos, s1.length());
			 line.insert(pos, s2);
			 pos += s2.length();
		 }
		output << line << std::endl;
	}
	input.close();
	output.close();
	return 0;
}