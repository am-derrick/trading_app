#include "MerkelMain.h"
#include <iostream>
#include <map>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <limits>


MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    int input;
	currentTime = orderBook.getEarliestTime();
    while (true)
	{
        printMenu();
		input = getUserOption();
		processUserOption(input);
	}
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

	std::cout << "Current time is " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
	std::cout << "Help - your aim is to make money." << std::endl;
	std::cout << "Analyse the market and make offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
	for (std::string const& p : orderBook.getKnownProducts())
	{
		std::cout << "Product: " << p << std::endl;
		std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
									p, currentTime);
		std::vector<OrderBookEntry> ords = orderBook.getOrders(OrderBookType::bid,
									p, currentTime);
		std::cout << "Asks seen: " << entries.size() << std::endl;
		std::cout << "Bids made: " << ords.size() << std::endl;
		std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
		std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;

		std::cout << "Total is: " << OrderBook::calculateTotal(entries) << std::endl;
	}
	/*
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
	*/
}

void MerkelMain::enterAsk()
{
	std::cout << "Make an ask - enter the amount: product,price,amount, eg ETH/BTC,200,0.5 " << std::endl;
	std::string input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);

	std::vector<std::string> tokens = CSVReader::tokenize(input, ',');
	if (tokens.size() != 3)
	{
		std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
	}
	else
	{
		try {
			OrderBookEntry obe = CSVReader::stringsToOBE(
			tokens[1],
			tokens[2],
			currentTime,
			tokens[0],
			OrderBookType::ask
			);
		} catch (const std::exception& e) {
			std::cout << "MerkelMain::enterAsk Bad input! " << std::endl;
		}
	}
		
	
	std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
	std::cout << "Make a bid - enter the amount " << std::endl;
}

void MerkelMain::printWallet()
{
	std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
	std::cout << "Going to next time frame." << std::endl;
	currentTime = orderBook.getNextTime(currentTime);
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
			enterAsk();
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
