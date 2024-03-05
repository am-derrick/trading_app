#ifndef MERKEL_MAIN_H
#define MERKEL_MAIN_H

class MerkelMain
{
    public:
        MerkelMain();
        /** call this to run the sim*/
        void init();
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
};

#endif