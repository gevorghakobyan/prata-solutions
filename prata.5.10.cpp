//Write a program using nested loops that asks the user to enter a value for the
//number of rows to display. It should then display that many rows of asterisks, with
//one asterisk in the first row, two in the second row, and so on. For each row, the
//asterisks are preceded by the number of periods needed to make all the rows
//display a total number of characters equal to the number of rows.A sample run
//would look like this:

#include <iostream>

int main(void)
{
	int num;
	std::cout << "Enter a number: _\b";
	std::cin >> num;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			std::cout << ".";
		};
		for (int k = 0; k < i; k++)
		{
			std::cout << "*";
		};
		std::cout << std::endl;
	};	

	return 0;
};
