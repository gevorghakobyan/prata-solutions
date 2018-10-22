#include "prata.11.7.h"

int main()
{
	Complex a(3.0, 4.0);
	Complex c;
	while (std::cout << "Enter a complex number (q to quit):'\n" && std::cin >> c)
	{
		std::cout << "c is " << c << '\n';
		std::cout << "Complex conjugate is " << ~c << '\n';
		std::cout << "a is " << a << '\n';
		std::cout << "a + c is " << a + c << '\n';
		std::cout << "a - c is " << a - c << '\n';
		std::cout << "a * c is " << a * c << '\n';
		std::cout << "2 * c is " << 2 * c << '\n';
	};
	std::cout << "Done!\n";
	return 0;
};
