#include <iostream>

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

int getUserOption()
{
	int userOption;

	std::cout << "Choose an option 1-6" << std::endl;
	std::cin >> userOption;
	std::cout << "You chose: " << userOption << std::endl;
	return userOption;	
}

void processUserOption(int userOption)
{
	if (userOption == 0)
	{
		std::cout << "Invalid choice. Choose an option between 1-6" << std::endl;
	}
	if (userOption == 1)
	{
		std::cout << "Help - your aim is to make money; analyse the market and make offers." << std::endl;
	}
	if (userOption == 2)
	{
		std::cout << "Market looks good" << std::endl;
	}
	if (userOption == 3)
	{
		std::cout << "Make an offer" << std::endl;
	}
	if (userOption == 4)
	{
		std::cout << "Make a bid - enter the amount" << std::endl;
	}
	if (userOption == 5)
	{
		std::cout << "Your wallet is empty." << std::endl;
	}
	if (userOption == 6)
	{
		std::cout << "Going to next time frame." << std::endl;
	}
}

int main()
{
	while (true)
	{
		printMenu();
		int userOption = getUserOption();
		processUserOption(userOption);
	}

	return 0;
}
