#include "prata.14.2.h"

int main()
{
	std::cout << "Enter name of wine: ";
	char lab[50];
	std::cin.getline(lab, 50);
	std::cout << "Enter number of years: ";
	int yrs;
	std::cin >> yrs;
	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = { 48, 60, 72};
	Wine more("Gushing Grape Red",YRS, y, b);
	more.Show();
	std::cout << "Total bottles for " << more.Label() << ": " << more.sum() << std::endl;
	std::cout << "Bye\n";
	return 0;
};
