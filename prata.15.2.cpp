#include "prata.15.2.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << std::endl;
			std::cout << "Enter next set of number <q to quit>: ";
		}
		catch (bad_hmean & bg)
		{
			std::cout << bg.what();
			std::cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean & hg)
		{
			std::cout << hg.what();
			std::cout << "Sorry, you don't get to play any more.\n";
		};
	};
	std::cout << "Bye!\n";
	return 0;
};

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean();
	};
	return 2.0 * a * b / (a + b);
};

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean();
	};
	return std::sqrt(a * b);
};
