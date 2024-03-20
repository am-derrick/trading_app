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


        /** returns the earliest time in the orderbook*/
        std::string getEarliestTime();
        /** returns the next time after the sent time in the orderbook
        * if there's no timestamp, wraps around to the start
        */
        std::string getNextTime(std::string timestamp);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
        
        static double calculateTotal(std::vector<OrderBookEntry>& orders);

    private:
        std::vector<OrderBookEntry> orders;       

};