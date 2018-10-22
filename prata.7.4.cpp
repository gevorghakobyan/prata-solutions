/*Many state lotteries use a variation of the simple lottery portrayed by Listing 7.4. In
these variations you choose several numbers from one set and call them the field
numbers. For example, you might select five numbers from the field of 1–47).You
also pick a single number (called a mega number or a power ball, etc.) from a sec-
ond range, such as 1–27.To win the grand prize, you have to guess all the picks cor-
rectly.The chance of winning is the product of the probability of picking all the
field numbers times the probability of picking the mega number. For instance, the
probability of winning the example described here is the product of the probability
of picking 5 out of 47 correctly times the probability of picking 1 out of 27 cor-
rectly. Modify Listing 7.4 to calculate the probability of winning this kind of lottery.*/

#include <iostream>

//function prototype
long double probability(unsigned numbers, unsigned picks, unsigned mega);

int main()
{

	double field_total, field_choices, mega_total;
	std::cout << "Enter the total number of choices on the game card, the number of picks allowed and the number of mega choices:" << std::endl;

//loop to request new lottery numbers, calculate and display the probability of winning
	while ((std::cin >> field_total >> field_choices >> mega_total) && field_choices <= field_total)
	{
	std::cout << "You have one chance in " << probability(field_total, field_choices, mega_total) << " of winning." << std::endl << "Next three numbers (q to quit): ";
	}
	std::cout << "BYE!" << std::endl;
	return 0;
}

// the following function calculates the probability of given lottery
long double probability(unsigned numbers, unsigned picks, unsigned mega)
{
	long double result = 1.0; 
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p ;
	result = result * 1 / mega;
	return result;
}
