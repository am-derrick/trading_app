#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::vector<std::string> tokenize(std::string csvLine, char separator)
{
	std::vector<std::string> tokens;
	
	signed int start, end;
	std::string token;

	start = csvLine.find_first_not_of(separator, 0);

	do {
		end = csvLine.find_first_of(separator, start);

		if (start == csvLine.length() || start == end)
		{
			break;
		}
		if (end >= 0)
		{
			token = csvLine.substr(start, end - start);
		}
		else
		{
			token = csvLine.substr(start, csvLine.length() - start);
		}
		tokens.push_back(token);
		start = end + 1;

	}
	while (end > 0);

	return tokens;
}

int main()
{
	std::ifstream csvFile{"20200317.csv"};
	std::string line;
	std::vector<std::string> tokens;

	if (csvFile.is_open())
	{
		while (std::getline(csvFile, line))
		{
			std::cout << line << std::endl;
			tokens = tokenize(line, ',');
			if (tokens.size() !=5 )
			{
				std::cout << "Bad line " << std::endl;
				continue;
			}

			try
			{
				double price = std::stod(tokens[3]);
				double amount = std::stod(tokens[4]);
				std::cout << price << ": " << amount << std::endl;
			} catch (const std::exception& e)
			{
				std::cout << "Bad float! " << tokens[3] << std::endl;
				std::cout << "Bad float! " << tokens[4] << std::endl;
				continue;
			}
			

			for (const std::string& t : tokens)
			{
				std::cout << t << std::endl;
			}
		}

		csvFile.close();
	}
	else
	{
		std::cout << "File could not open" << std::endl;
	}

	return 0;
}
