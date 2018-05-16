/*Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors, and the rest of the file should
consist of pairs of lines, with the first line of each pair being a contributor’s name
and the second line being a contribution.That is, the file should look like this:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000*/

//exercise 6 is below

/*Put together a program that keeps track of monetary contributions to the Society
for the Preservation of Rightful Influence. It should ask the user to enter the num-
ber of contributors and then solicit the user to enter the name and contribution of
each contributor.The information should be stored in a dynamically allocated array
of structures. Each structure should have two members: a character array (or else a
string object) to store the name and a double member to hold the amount of the
contribution.After reading all the data, the program should display the names and
amounts donated for all donors who contributed $10,000 or more.This list should be headed by the label Grand Patrons.After that, the program should list the
remaining donors.That list should be headed Patrons. If there are no donors in one
of the categories, the program should print the word “none.”Aside from displaying
two categories, the program need do no sorting.*/

#include <iostream>
#include <fstream>
#include <string>



int main(void)
{

	char file_name[40];
	int donor_num;
	std::string donor_name;
	double donor_sum;
	std::cout << "Enter the file name: ";
	std::cin.getline(file_name, 39);
	std::ofstream fout;
	std::ifstream fin;


//opens file to start filling it with data
	fout.open(file_name);
	if (fout.is_open())
	{
		std::cout << "Enter the number of donors: ";
		std::cin >> donor_num;
		std::cin.get();
		fout << donor_num << std::endl;

//loop requests donor names and contributions
		for (int i = 0; i < donor_num; i++)
		{	
			std::cout << "Enter the name 	of the " << i + 1 << "-th donor: ";
			getline(std::cin, donor_name);
			fout << donor_name << std::endl;
			std::cout << "Enter the sum the " << i + 1 << "-th donor has contributed: ";
			std::cin >> donor_sum;
			std::cin.get();
			fout << donor_sum << std::endl;
		};
		fout.close();
	}
	else
	{
		std::cout << "The file couldn't be opened." << std::endl;
	};


	
//opens file to display grand patrons
	fin.open(file_name);
	if (fin.is_open())	
	{
		int grand_num = 0;
		fin >> donor_num;
		fin.get();
		std::cout << "Grand Patrons" << std::endl;
		while (std::getline(fin, donor_name))
		{	
			fin >> donor_sum;
			fin.get();
			if (donor_sum > 10000)
			{				
				std::cout << donor_name << ": " << donor_sum << std::endl;
				grand_num++;
			};
		};
		if (grand_num == 0)
			std::cout << "None." << std::endl;
	fin.close();
	}
	else
	{
		std::cout << "The file couldn't be opened." << std::endl;
	};


//opens file to display other patrons
	fin.open(file_name);
	if (fin.is_open())	
	{
		int patron_num = 0;
		fin >> donor_num;
		fin.get();
		std::cout << "Patrons" << std::endl;
		while (std::getline(fin, donor_name))
		{	
			fin >> donor_sum;
			fin.get();
			if (donor_sum <= 10000)
			{				
				std::cout << donor_name << ": " << donor_sum << std::endl;
				patron_num++;
			};
		};
		if (patron_num == 0)
			std::cout << "None." << std::endl;
	fin.close();
	}
	else
	{
		std::cout << "The file couldn't be opened." << std::endl;
	};


	return 0;
};
