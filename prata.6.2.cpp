//Write a program that reads up to 10 donation values into an array of double . (Or, if
//you prefer, use an array template object.) The program should terminate input on
//non-numeric input. It should report the average of the numbers and also report
//how many numbers in the array are larger than the average.

#include <iostream>

//number of maximum donations to enlist
const int DonNum = 10;

int main(void)
{
//each donation input
	double don;
//array incorporating single donations
	double donations[DonNum];
//sum of all donations
	double sum = 0;
//number of donations de facto entered 
	int i = 0;
//loop to add donations to the array
	while (i < DonNum)
		{
			std::cout << "Enter donation sum: _\b";
//checks whether the input is a double (meaning that it's a donation)
			if (std::cin >> don)
				{
					donations[i] = don;
					sum += don;
					i++;
				}
//breaks out of loop if the input is non-numeric
			else
				{
					break;
				};
		};
//the average donation size
	double average = sum / i;
//counts the number of donations greater than the average
	int greater_count = 0;
	for (int j = 0; j < i; j++)
		{
			if (donations[j] > average)
				{
					greater_count++;
				};		
		};
//final output statement
	std::cout << "The average amount of donations is " << average << " and " << greater_count << " donations are larger than the average.";
	return 0;
};
