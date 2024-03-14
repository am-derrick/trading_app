#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "ComputePrices.h"
#include "CSVReader.h"


int main()
{
	MerkelMain app{};
	app.init();
}


/*
	ComputePrices compute{};
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
	*/