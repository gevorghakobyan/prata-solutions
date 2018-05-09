//Write a program that requests the user to enter two integers.The program should then calculate and report the sum of all the integers between and including the two integers.At this point, assume that the smaller integer is entered first. For example, if the user enters 2 and 9 , the program should report that the sum of all the integers from 2 through 9 is 44.

#include <iostream>

int main(void)
{
	std::cout << "Enter the first integer: _\b";
	int first_num;
	std::cin >> first_num;
	std::cout << "Enter the second integer: _\b";
	int sec_num;
	std::cin >> sec_num;


	int sum = 0;
	for (int i = first_num; i <= sec_num; i ++)
	{
		sum += i;
	};
	std::cout << sum << std::endl;

	return 0;
};


