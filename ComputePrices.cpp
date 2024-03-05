#include "ComputePrices.h"
#include <vector>


ComputePrices::ComputePrices()
{

}

void ComputePrices::init()
{

}

double ComputePrices::computeAveragePrice(std::vector<OrderBookEntry>& orders)
{
	double sum = 0.0;
	for (OrderBookEntry& order : orders)
	{
		sum += order.price;
	}

	return sum / orders.size();
}


double ComputePrices::computeLowPrice(std::vector<OrderBookEntry>& orders)
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


double ComputePrices::computeHighPrice(std::vector<OrderBookEntry>& orders)
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


double ComputePrices::computePriceSpread(std::vector<OrderBookEntry>& orders)
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