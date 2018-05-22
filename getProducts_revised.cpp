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
	return 0;
};


//product calculating function definition
void getProducts(int array[], int array2[], int size)
{
	array2[0] = 1;
	for (int i = 1; i < size; i++)
	{	
		array2[i] = array[i - 1] * array2[i - 1];		
	};
	int temp = array[size - 1];
	for (int i = 2; i < size + 1; i++)
	{
		array2[size - i] *= temp;
		temp *= array[size - i];
	};
	for (int i = 0; i < size; i++)
	{
		std::cout << array2[i] << " ";
	};
	std::cout << std::endl;
};
