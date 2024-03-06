#include "AustrianReviews.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::string> tokenize(std::string csvRow, char delimiter)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;

    start = csvRow.find_first_not_of(delimiter, 0);

    do
    {
        end = csvRow.find_first_of(delimiter, start);

        if (start == csvRow.length() || start == end)
        {
            break;
        }

        if (end >= 0)
        {
            token = csvRow.substr(start, end - start);
        }
        else
        {
            token = csvRow.substr(start, csvRow.length());
        }

        tokens.push_back(token);
        start = end + 1;
    }
    while (end > 0);

    return tokens;
}

int main()
{
    std::ifstream csvFile{"austrian_airlines_reviews.csv"};
    std::string row;
    std::vector<std::string> tokens;

    if (csvFile.is_open())
    {
        while (getline(csvFile, row))
        {
            //std::cout << row << std::endl;
            tokens = tokenize(row, ',');
            for (const std::string& token : tokens)
            {
                std::cout << token << std::endl;
            }
        }
        csvFile.close();
    }
    else
    {
        std::cout << "The csv file could not be opened" << std::endl;
    }

    return 0;
}