// Redo Listing 5.4 using a type array object instead of a built-in array and type 
//long double instead of long long . Find the value of 100!

#include <iostream>
#include <array>

const int ArSize = 101;

int main(void)
{
	std::array<long double, ArSize> fact;
	

	fact[0] = 1;
	for (int i = 1; i < ArSize; i++)
	{
		fact[i] = fact[i - 1] * i;
		std::cout << i << "! = " << fact[i] << std::endl;
	};

	
return 0;
};
