#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>


class CSVReader
{
    public:
        CSVReader();
        /** parse the sent CSV file into multiple
        * OrderBookEntry objects which should contain
        * lines like:
        * 2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187305,6.85567013
        */
        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenize(std::string csvLine, char separator);
        static OrderBookEntry stringsToOBE(std::string price,
                                            std::string amount,
                                            std::string timestamp,
                                            std::string product,
                                            std::string OrderBookType);

    private:
        static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};