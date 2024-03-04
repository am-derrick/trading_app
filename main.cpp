#include <iostream>
#include <map>
#include <string>
#include <vector>

enum class OrderBookType{ask, bid};

class OrderBookEntry
{
	public:
		/** Create a new OrderBookEntry with the price
		* set to the sent value
		*/
		OrderBookEntry( double _price,
						double _amount,
						std::string _timestamp,
						std::string _product,
						OrderBookType _orderType);
		
		double price;
		double amount;
		std::string timestamp;
		std::string product;
		OrderBookType orderType;
};

OrderBookEntry::OrderBookEntry (double _price,
								double _amount,
								std::string _timestamp,
								std::string _product,
								OrderBookType _orderType)
: price(_price),
  amount (_amount),
  timestamp (_timestamp),
  product (_product),
  orderType (_orderType)
{

}

void printMenu()
{
	std::cout << "1: Print help " << std::endl;
	std::cout << "2: Print exchange stats " << std::endl;
	std::cout << "3: Place an ask " << std::endl;
	std::cout << "4: Place a bid " << std::endl;
	std::cout << "5: Print wallet " << std::endl;
	std::cout << "6: Continue" << std::endl;

	std::cout << "============= " << std::endl;
}

void printHelp()
{
	std::cout << "Help - your aim is to make money." << std::endl;
	std::cout << "Analyse the market and make offers." << std::endl;
}

void printMarketStats()
{
	std::cout << "Market looks good" << std::endl;
}

void enterOffer()
{
	std::cout << "Make an offer" << std::endl;
}

void enterBid()
{
	std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
	std::cout << "Your wallet is empty." << std::endl;
}

void gotoNextTimeframe()
{
	std::cout << "Going to next time frame." << std::endl;
}

int getUserOption()
{
	int userOption;

	std::cout << "Choose an option 1-6" << std::endl;
	std::cin >> userOption;
	std::cout << "You chose: " << userOption << std::endl;
	return userOption;	
}

double computeAveragePrice(std::vector<OrderBookEntry>& orders)
{
	double sum = 0.0;
	for (OrderBookEntry& order : orders)
	{
		sum += order.price;
	}

	return sum / orders.size();
}


double computeLowPrice(std::vector<OrderBookEntry>& orders)
{
	double lowest = orders[0].price;
	for (OrderBookEntry& order : orders)
	{
		if (order.price < lowest)
		{
			lowest = order.price;
		}
	}

	return lowest;
}


double computeHighPrice(std::vector<OrderBookEntry>& orders)
{
	double highest = orders[0].price;
	for (OrderBookEntry& order : orders)
	{
		if (order.price > highest)
		{
			highest = order.price;
		}
	}

	return highest;
}


double computePriceSpread(std::vector<OrderBookEntry>& orders)
{
	double min = orders[0].price;
	double max = orders[0].price;

	for (OrderBookEntry& order : orders)
	{
		if (order.price < min)
		{
			min = order.price;
		}
		if (order.price > max)
		{
			max = order.price;
		}
	}

	return max - min;
}

int main()
{
	std::vector<OrderBookEntry> orders;

	OrderBookEntry order1{7.4456,
						0.02186, 
						"2020/04/17 17:01:24.884492",
						"ETH/BTC",
						OrderBookType::bid};

	OrderBookEntry order2{6.346,
						0.05166, 
						"2020/03/17 19:30:24.884492",
						"DOGE/BTC",
						OrderBookType::bid};

	OrderBookEntry order3{3.5486,
						0.04166, 
						"2020/06/17 18:05:27.884492",
						"BTC/USDT",
						OrderBookType::ask};

	orders.push_back(order1);
	orders.push_back(order2);
	orders.push_back(order3);

	std::cout << orders[0].price <<std::endl;

	for (OrderBookEntry& order : orders)
	{
		std::cout << order.price << std::endl;
	}

	std::cout << "The average price is " << computeAveragePrice(orders) << std::endl;
	std::cout << "The lowest price is " << computeLowPrice(orders) << std::endl;
	std::cout << "The highest price is " << computeHighPrice(orders) << std::endl;
	std::cout << "The price spread is " << computePriceSpread(orders) << std::endl;

    /*
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
	*/

	return 0;
}
