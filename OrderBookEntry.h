#include <string>

enum class OrderBookType{ask, bid};

class OrderBookEntry
{
	public:
		/** Creates a new OrderBookEntry with the price, amount,
		* timestamp, product and orderbooktype set to the sent
		* their respective values.
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