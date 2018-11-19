/*Write a program that repeatedly asks the user to enter pairs of numbers until at
least one of the pair is 0 . For each pair, the program should use a function to calcu-
late the harmonic mean of the numbers.The function should return the answer to
main() , which should report the result.The harmonic mean of the numbers is the
inverse of the average of the inverses and can be calculated as follows:
harmonic mean = 2.0 × x × y / (x + y)*/

#include <iostream>

//counts the harmonious mean of two numbers
double harm_mean(int x, int y);

//integer requesting function
void request_numbers();

//variables for storing numbers
int a;
int b;

int main(void)
{
//requests the first pair of numbers
	request_numbers();

//loop to display harmonious mean and request a new pair of integers until one in a pair is 0
	while (a != 0 && b != 0)
	{
		double mean = harm_mean(a, b);
		std::cout << "Harmonic mean of the above entered numbers is " << mean << "." << std::endl;
	request_numbers();
	};

	std::cout << "BYE!" << std::endl;
	return 0;
};

//definition of the function calculating harmonious mean
double harm_mean(int x, int y)
{
	double mean = 2.0 * x * y / (x + y);
	return mean;
};

//definition of the function that request integer input
void request_numbers()
{
	std::cout << "Enter the first integer of the pair: ";
	std::cin >> a;
	std::cout << "Enter the second integer of the pair: ";
	std::cin >> b;
};
