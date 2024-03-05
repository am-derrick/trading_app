#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "ComputePrices.h"



int main()
{
	MerkelMain app{};
	ComputePrices compute{};
	
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

	std::cout << "The average price is " << compute.computeAveragePrice(orders) << std::endl;
	std::cout << "The lowest price is " << compute.computeLowPrice(orders) << std::endl;
	std::cout << "The highest price is " << compute.computeHighPrice(orders) << std::endl;
	std::cout << "The price spread is " << compute.computePriceSpread(orders) << std::endl;
	std::cout << std::endl;

	app.init();

	return 0;
}
