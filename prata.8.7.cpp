/* Modify Listing 8.14 so that it uses two template functions called SumArray() to
return the sum of the array contents instead of displaying the contents.The pro-
gram now should report the total number of things and the sum of all the debts.*/

#include <iostream>

template <typename T>
void SumArray(T arr[], int n);

template <typename T>
void SumArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};



int main(void)
{
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];

// set pointers to the amount members of the structures in mr_E	
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	SumArray(things, 6);
	SumArray(pd, 3);

	return 0;	
};



template <typename T>
void SumArray(T arr[], int n)
{
	int sum = 0;
	for (; n > 0; n--)
		sum += arr[n - 1];
	std::cout << "The sum of all the things is " << sum << "." << std::endl;
};

template <typename T>
void SumArray(T * arr[], int n)
{
	double sum_debt = 0;
	for (; n > 0; n--)
		sum_debt += *arr[n - 1];
	std::cout << "The sum of all the debts is " << sum_debt << "." << std::endl;
};
