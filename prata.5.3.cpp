//Write a program that asks the user to type in numbers.After each entry, the pro-
//gram should report the cumulative sum of the entries to date.The program should
//terminate when the user enters 0 .

#include <iostream>

int main(void)
{
	int sum = 0;
	int num;
	do
	{
	std::cout << "Enter a number: _\b";
	std::cin >> num;
	sum += num;
	std::cout << "The cumulative sum now is " << sum << "." << std::endl;
	} while (num != 0);
	std::cout << "YOU entered 0 in which case program aborts.\n";
	
	return 0;
};
