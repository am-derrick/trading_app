#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
    public:
        /** construct, a reading a csv data file */
        OrderBook(std::string filename);
        /** return a vector of all known products in the dataset */
        std::vector<std::string> getKnownProducts();
        /** return vector of Orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                                std::string product,
                                                std::string timestamp);
    private:
        std::vector<OrderBookEntry> orders;       

};