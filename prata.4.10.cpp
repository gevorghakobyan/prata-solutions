//c++11 program using array objects

// program that requests the user to enter three times for the 40-yd dash (or
//40-meter, if you prefer) and then displays the times and the average. Use an array
//object to hold the data. (Use a built-in array if array is not available.)

#include <iostream>
#include <array>

const int DashNum = 3;

int main(void)
{

	std::array<int, DashNum> dash;

// asks for dashes and adds them to the array
	std::cout << "Enter the first dash: _\b";
	std::cin >> dash[0];
	std::cout << "now the second dash: _\b";
	std::cin >> dash[1];
	std::cout << "and here goes the third one: _\b";
	std::cin >> dash[2];

// counts the average and displays
	float average = (dash[0] + dash[1] + dash[2]) / float (DashNum);
	std::cout << "The average for all " << DashNum << " dashes is " << average << " yards.\n";


	return 0;

};
