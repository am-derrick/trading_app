#include <iostream>
#include <map>

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

int main()
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
