#include "MerkelMain.h"
#include <iostream>
#include <map>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"


MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
	loadOrderBook();
    int input;
    while (true)
	{
        printMenu();
		input = getUserOption();
		processUserOption(input);
	}
}

void MerkelMain::loadOrderBook()
{
	orders = CSVReader::readCSV("20200317.csv");
}

void MerkelMain::printMenu()
{
	std::cout << "1: Print help " << std::endl;
	std::cout << "2: Print exchange stats " << std::endl;
	std::cout << "3: Place an ask " << std::endl;
	std::cout << "4: Place a bid " << std::endl;
	std::cout << "5: Print wallet " << std::endl;
	std::cout << "6: Continue" << std::endl;

	std::cout << "============= " << std::endl;
}

void MerkelMain::printHelp()
{
	std::cout << "Help - your aim is to make money." << std::endl;
	std::cout << "Analyse the market and make offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
	std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
	unsigned int bids = 0;
	unsigned int asks = 0;
	for (OrderBookEntry& e : orders)
	{
		if (e.orderType == OrderBookType::ask)
		{
			asks ++;
		}
		if (e.orderType == OrderBookType::bid)
		{
			bids ++;
		}
	}
	std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
}

void MerkelMain::enterOffer()
{
	std::cout << "Make an offer" << std::endl;
}

void MerkelMain::enterBid()
{
	std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
	std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
	std::cout << "Going to next time frame." << std::endl;
}

int MerkelMain::getUserOption()
{
	int userOption;

	std::cout << "Choose an option 1-6" << std::endl;
	std::cin >> userOption;
	std::cout << "You chose: " << userOption << std::endl;
	return userOption;	
}

void MerkelMain::processUserOption(int userOption)
{
	switch (userOption) 
	{
		case 0:
			std::cout << "Invalid choice. Choose an option between 1-6" << std::endl;
			break;
		case 1:
			printHelp();
			break;
		case 2:
			printMarketStats();
			break;
		case 3:
			enterOffer();
			break;
		case 4:
			enterBid();
			break;
		case 5:
			printWallet();
			break;
		case 6:
			gotoNextTimeframe();
			break;
	}
}

/*
int MerkelMain::inputOption()
{
    std::map<int, void(*)()> menu;
	menu[1] = printHelp;
	menu[2] = printMarketStats;
	menu[3] = enterOffer;
	menu[4] = enterBid;
	menu[5] = printWallet;
	menu[6] = gotoNextTimeframe;

    while (true)
	{
		printMenu();
		int userOption = getUserOption();

		auto i = menu.find(userOption);
		if (i != menu.end())
		{
			i->second();
		}
		else
		{
			std::cout << "Invalid choice. Choose an option between 1-6" << std::endl; 
		}
	}

    return 0;
}
*/
