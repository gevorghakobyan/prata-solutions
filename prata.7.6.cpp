/*Write a program that uses the following functions:
Fill_array() takes as arguments the name of an array of double values and an
array size. It prompts the user to enter double values to be entered in the array. It
ceases taking input when the array is full or when the user enters non-numeric
input, and it returns the actual number of entries.
Show_array() takes as arguments the name of an array of double values and an
array size and displays the contents of the array.
Reverse_array() takes as arguments the name of an array of double values and an
array size and reverses the order of the values stored in the array.
The program should use these functions to fill an array, show the array, reverse the
array, show the array, reverse all but the first and last elements of the array, and then
show the array.*/

#include <iostream>

//a couple of prototypes
int fill_array(double array [], int size);
void show_array(double array [], int size);
void reverse_array(double array [], int size);


int main(void)
{
	int arr_size;
	std::cout << "Enter the number of elements the array is going to have: ";
	std::cin >> arr_size;
	double arr[arr_size];
//fills the array
	int actual_size = fill_array(arr, arr_size);
//shows the actual size
	std::cout << "The actual size of the array is " << actual_size << std::endl;
//displays the array
	show_array(arr, actual_size);
//reverses the array
	reverse_array(arr, actual_size);
//displays reversed array
	show_array(arr, actual_size);
//reverses array again except for the first and last elements
	reverse_array(arr + 1, actual_size - 2);
//displays the array reversed twice
	show_array(arr, actual_size);
	
	return 0;
};

//definition of the array filling fucntion
int fill_array(double array [], int size)
{
	int i = 0;
	double num;
	std::cout << "Enter double array element #1: ";
	while (std::cin >> num)
	{
		array[i] = num;
		if (!(++i < size))
			break;
		std::cout << "Enter double array element #" << i + 1 << ": ";
	};
	return i;
};

//array element displaying functions definition
void show_array(double array [], int size)
{	
	std::cout << "The elements of the array are: ";
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
};

//reversing function definition
void reverse_array(double array[], int size)
{
	int i = 0;
	int j = size - 1;
	for (; i < j; i++, j--)
	{
		double temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	};	
	std::cout << "The array has been reversed." << std::endl;
};
