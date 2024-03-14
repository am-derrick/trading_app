#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
    public:
        MerkelMain();
        /** call this to run the app*/
        void init();
    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        // int inputOption();
        void processUserOption(int userOption);


        std::vector<OrderBookEntry> orders;
};