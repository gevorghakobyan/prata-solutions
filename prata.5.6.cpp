//c++11 compilataion is a must

//6. Do Programming Exercise 5 but use a two-dimensional array to store input for 3
//years of monthly sales. Report the total sales for each individual year and for the
//combined years.
//Exercise 5 is bellow.

//5. You sell the book C++ for Fools.Write a program that has you enter a year’s worth
//of monthly sales (in terms of number of books, not of money).The program should
//use a loop to prompt you by month, using an array of char * (or an array of
//string objects, if you prefer) initialized to the month strings and storing the input
//data in an array of int .Then, the program should find the sum of the array con-
//tents and report the total sales for the year.

#include <iostream>
#include <array>

const int NumMonth = 12;
const int Year = 3;

int main(void)
{
	

	std::array<std::string, NumMonth> month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // array of month names as string objects
	int sales[Year][NumMonth]; //array of sales of each month of each year
	int total_sales = 0; //total count of 3 year sales


	for (int y = 0; y < Year; y++) //iterates through 3 years
	{
		int each_year_sales = 0; //count of sales for each year

		for (int m = 0; m < NumMonth; m ++) //iterates through each month of a single year 
		{
			std::cout << "Enter the sales for " << month[m] << " of year " << y + 1 << ": _\b";
			std::cin >> sales[y][m];
			each_year_sales += sales[y][m];
		};
		

		std::cout << "Sales for the year " << y + 1 << ": " << each_year_sales << "." << std::endl;
		total_sales += each_year_sales;
	}; // main loop ends here
	

	std::cout << "Total sales for " << Year << " years: " << total_sales << "." << std::endl;


	return 0;
}
