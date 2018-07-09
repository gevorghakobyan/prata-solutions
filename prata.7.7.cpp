/*Redo Listing 7.7, modifying the three array-handling functions to each use two
pointer parameters to represent a range.The fill_array() function, instead of
returning the actual number of items read, should return a pointer to the location
after the last location filled; the other functions can use this pointer as the second
argument to identify the end of the data.*/

#include <iostream>

const int Max = 5;

//function prototype
int fill_array(double * start, double * end);
void show_array(double const * start, double const * end);
void revalue(double r, double * start, double * end);

int main()
{
	double properties[Max];

	int size = fill_array(properties, properties + Max);
	show_array(properties, properties + Max);
	if (size > 0)
	{
		std::cout << "Enter revaluation factor: ";
		double factor;
		while (!(std::cin >> factor))
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Bad input; Please enter a number: ";
		};
		revalue(factor, properties, properties + size);
		show_array(properties, properties + size);
	};
	std::cout << "Done. \n";
	std::cin.get();
	std::cin.get();
	return 0;
};


//fills the array using pointers for implementing array range technique
int fill_array(double * start, double * end)
{
	double temp;
	int i;
	for (i = 0; start + i != end; i++)
	{
		std::cout << "Enter value #" << (i + 1) << ": ";
		std::cin >> temp;
		if (!std::cin)
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
			{
				continue;
			};
			std::cout << "Bad input; input precess terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*(start + i) = temp;
	};
	return i;
};


//display array elements
void show_array(double const * start, double const * end)
{
	for (int i = 0; start + i != end; i++)
	{
		std::cout << "Property #" << (i + 1) << ": $";
		std::cout << *(start + i) << std::endl;
	};
};

//revalue array elements 
void revalue(double r, double * start, double * end)
{
	for (int i = 0; start + i != end; i++)
		*(start + i) *= r;
};
