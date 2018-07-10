#include <iostream>

//function prototype
double fact(double n);

int main(void)
{
	std::cout << "Enter a number: ";
//loop to request new numbers, counts and displays factorial, until anything but a positive number is typed
	while (std::cin >> num)
	{	
		std::cout << num << "'s factorial is " << fact(num) << std::endl;
		std::cout << "Enter a number: ";
	};
	std::cout << "BYE!" << std::endl;
	return 0;
};

//definition of the function that count's factorial of a given number
double fact(double n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
};
