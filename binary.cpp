#include <iostream>

int binary_search(int array[], int start, int size, int num);

int main(void)
{
	int num;
	int index = 0;
	int array[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	std::cout << "Enter a number from 0 to 20 inclusive and to display it's index in the array if it's present there: ";
	std::cin >> num;
	int result = binary_search(array, 0, 21, num);
	std::cout << result;
	return 0;
};

//binary searce recursive function definition
int binary_search(int array[], int start, int size, int num)
{
	int index;
	int half = size / 2;
	if (half == 0)
	{
		std::cout << "No such number in the array.";
		return -1;
	};
	if (array[start + half] == num)
		return start + half;
	if (array[start + half] < num)
		binary_search(array, start + half, size - half, num);
	else
		binary_search(array, start, half, num);
};
