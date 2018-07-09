/*Write a program that asks the user to enter up to 10 golf scores, which are to be
stored in an array.You should provide a means for the user to terminate input prior
to entering 10 scores.The program should display all the scores on one line and
report the average score. Handle input, display, and the average calculation with
three separate array-processing functions.*/

#include <iostream>

const int SCORES = 10;
//function prototypes
void input(int arr[], int size);
void display(int arr[], int size);
float average(int arr[], int size);
//number of inputs that are going to be enlisted
int input_num = 0;

int main(void)
{
//array for storing the scores
	int arr[SCORES];

	input(arr, SCORES);
	display(arr, input_num);
	std::cout << "The average of the " << input_num << " scores is " << average(arr, input_num) << "." << std::endl;	

	return 0;
};

//function definition for requesting scores and storing them in an array
void input(int arr[], int size)
{	
	for (; input_num < size; input_num++)
	{
		std::cout << "Enter the " << input_num + 1 << "-th score: ";
		std::cin >> arr[input_num];
		if (arr[input_num] <= 0)
			break;
	};
};

//function definition for displaying array elements
void display(int arr[], int size)
{
	int i = 0;
	while (i < size)
	{
		std::cout << arr[i] << " ";
		i++;
	};
	std::cout << std::endl;
};

//function definition for calculating the average of the elements of an array
float average(int arr[], int size)
{	
	int sum = 0;
	for (int i = 0; i < size; i++)
	 	sum += arr[i];

	float ave = float (sum) / float (size);
	return ave;
};
