/*Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it overloads all six
relational operators.The operators should compare the pounds members and return
a type bool value.Write a program that declares an array of six Stonewt objects and
initializes the first three objects in the array declaration.Then it should use a loop
to read in values used to set the remaining three array elements.Then it should
report the smallest element, the largest element, and how many elements are greater
or equal to 11 stone. (The simplest approach is to create a Stonewt object initial-
ized to 11 stone and to compare the other objects with that object.)
*/


#include <iostream>
#include "prata.11.6.h"


int main()
{

//stonewt array initialization part
	Stonewt arraysw[6] = {104.5, 83.7, 154};
	std::cout << "Enter the next 3 weigths (floating point numbers): " << std::endl;
	double pound;
	for (int i = 3; i < 6; ++i)
	{
		std::cin >> pound;
		arraysw[i] = Stonewt(pound);
	};

//finding the smallest and largest elements
	Stonewt smallest = arraysw[0];
	Stonewt largest = arraysw[0];
	for (int i = 1; i < 6; ++i)
	{
		if (smallest > arraysw[i])
		{
			smallest = arraysw[i];
		};
		if (largest < arraysw[i])
		{
			largest = arraysw[i];
		};
	};
	std::cout << "The smallest element is ";
	smallest.show_lbs();
	std::cout << "The largest element is ";
	largest.show_lbs();

//finding the number of elements greater than 11 stones
	Stonewt sw11(11, 0);
	int count = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (arraysw[i] >= sw11)
		{
			++count;
		};
	};
	std::cout << count << " many elements are greater or equal to 11 stones." << std::endl;




	return 0;
};

