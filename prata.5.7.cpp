//Design a structure called car that holds the following information about an auto-
//mobile: its make, as a string in a character array or in a string object, and the year
//it was built, as an integer.Write a program that asks the user how many cars to cata-
//log.The program should then use new to create a dynamic array of that many car
//structures. Next, it should prompt the user to input the make (which might consist
//of more than one word) and year information for each structure. 
//Finally, it should display the contents of each structure.

#include <iostream>
#include <string>

struct car 
{
	std::string make;
	int year;
};


int main(void)
{
	
//assertains the number of cars from the user and creates that numbered array of car structures dynamically
	int cars_num;	
	std::cout << "How many cars do you wish to catalog? _\b";
	std::cin >> cars_num;
	car * ptocar = new car [cars_num];


//requests the data of cars
	for (int i = 0; i < cars_num; i++) 
	{
		std::cout << "Car #" << i + 1 << ":" << std::endl;
		std::cin.get();
		std::cout << "Please enter the make: ";
		getline(std::cin, ptocar[i].make);
		std::cout << "Please enter the year made: _\b";
		std::cin >> ptocar[i].year;
	};
	

//echoes the overall information
	std::cout << "Here is your collection:\n";
	for (int i = 0; i < cars_num; i++)
	{
		std::cout << ptocar[i].year << " " << ptocar[i].make << std::endl;
	};	

	delete [] ptocar;

	return 0;
};
