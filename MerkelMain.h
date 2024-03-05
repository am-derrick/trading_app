

class MerkelMain
{
    public:
        MerkelMain();
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