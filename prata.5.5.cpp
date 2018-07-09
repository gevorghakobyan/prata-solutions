//You sell the book C++ for Fools.Write a program that has you enter a year’s worth
//of monthly sales (in terms of number of books, not of money).The program should
//use a loop to prompt you by month, using an array of char * (or an array of
//string objects, if you prefer) initialized to the month strings and storing the input
//data in an array of int .Then, the program should find the sum of the array con-
//tents and report the total sales for the year.

#include <iostream>

int main(void)
{
	

	const int NumOfMonths = 12;
	const char * month[NumOfMonths] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int sales[NumOfMonths];
	int total_sales = 0;


	for (int i = 0; i < NumOfMonths; i++)
	{
		std::cout << "Enter the sales figure for " << month[i] << ": _\b";
		std::cin >> sales[i];
		total_sales += sales[i];
	};
	std::cout << "The total sales for the given year are " << total_sales << std::endl;

	
return 0;
};
