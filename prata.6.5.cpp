/*The Kingdom of Neutronia, where the unit of currency is the tvarp, has the fol-
lowing income tax code:
First 5,000 tvarps: 0% tax
Next 10,000 tvarps: 10% tax
Next 20,000 tvarps: 15% tax
Tvarps after 35,000: 20% tax
For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 10,000 ×
0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps.Write a program that uses a
loop to solicit incomes and to report tax owed.The loop should terminate when
the user enters a negative number or non-numeric input.*/

#include <iostream>

int main(void)
{
	std::cout << "Enter your income: _\b";
	double income;
	double tax = 0;
	

//loop to request income input, counts the tax owed going through a couple of if statements as long as the income is higher than the amount specified in the if condition and counts the tax accordingly
	while (std::cin >> income && income > 0)
		{
			if (income > 5000)
				{
				tax = (income - 5000) * 0.1;
				if (income > 20000)
					{
					tax += (income - 20000) * 0.15;
					if (income > 35000)
						{
							tax += (income - 35000) * 0.2;
						};	
					};
				};
//outputs the tax and requests new income input	
			std::cout << "Your tax is " << tax << " tvarps.\n";
			std::cout << "Enter your income: _\b";
			};

	return 0;
};
