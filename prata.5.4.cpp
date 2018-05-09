//Daphne invests $100 at 10% simple interest.That is, every year, the investment earns
//10% of the original investment, or $10 each and every year:
//interest = 0.10 × original balance
//At the same time, Cleo invests $100 at 5% compound interest.That is, interest is 5%
//of the current balance, including previous additions of interest:
//interest = 0.05 × current balance
//Cleo earns 5% of $100 the first year, giving her $105.The next year she earns 5% of
//$105, or $5.25, and so on.Write a program that finds how many years it takes for
//the value of Cleo’s investment to exceed the value of Daphne’s investment and then
//displays the value of both investments at that time.

#include <iostream>

int main(void)
{
	int year = 0;
	const float cloe_interest = 0.05;
	float daphne_sum = 100;
	float cloe_sum = 100;

	do 
	{
		daphne_sum += 10;
		cloe_sum += cloe_sum * cloe_interest;
		year++;
	} while (cloe_sum < daphne_sum);



	std::cout << "After " << year << " years Cloe has more money than Daphne, and namely she's got " << cloe_sum << "$, while Daphne has " << daphne_sum << "$." << std::endl;

	return 0;
};
