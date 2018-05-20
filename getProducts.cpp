/*program takes an array of numbers and returns an array whos each i-th element is
 equal to the product of the all the elements of the other array, except for that
 other arrays i-th element*/

#include <iostream>

//function prototype
void getProducts(int array[], int array2[], int size);


int main(void)
{
//first array
	int array[] = {1, 2, 3, 4, 7};
//size of both arrays
	int size = sizeof(array) / sizeof(array[0]);
//array of products;
	int array_prod[size] = {0};
//calls the function to perform main calculation
	getProducts(array, array_prod, size);
	std::cout << std::endl;
	return 0;
};


//product calculating function definition
void getProducts(int array[], int array2[], int size)
{
	for (int i = 0; i < size; i++)
	{	
		int prod = 1;
		for (int j = 0; j < size; j++)
		{
			if (j == i)
				continue;
			prod *= array[j];
		};
		array2[i] = prod;
		std::cout << array2[i] << " ";
	};
};
