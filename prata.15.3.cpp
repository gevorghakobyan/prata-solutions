#include "prata.15.3.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z, g;
	
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			g = gmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
			std::cout << "Geometric mean of " << x << " and " << y << " is " << g << std::endl;
			std::cout << "Enter next set of number <q to quit>: ";
		}
		catch (bad_mean & bm)
		{
			std::cout << bm.what() << std::endl;
			break;
		};
	};
	std::cout << "Bye!\n";
	return 0;

	return 0;
};

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	};
	return 2.0 * a * b / (a + b);
};

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	};
	return std::sqrt(a * b);
};
