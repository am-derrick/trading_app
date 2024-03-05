#pragma once

#include <vector>
#include "OrderBookEntry.h"

class ComputePrices
{
    public:
        ComputePrices();
        void init();
        double computeAveragePrice(std::vector<OrderBookEntry>& orders);
        double computeLowPrice(std::vector<OrderBookEntry>& orders);
        double computeHighPrice(std::vector<OrderBookEntry>& orders);
        double computePriceSpread(std::vector<OrderBookEntry>& orders);
};