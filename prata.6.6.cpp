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
#include <string>

//structor for keeping each donors data
struct donorstr 
	{
	std::string name;
	double sum;
	};


int main(void)
{
	std::cout << "Enter the number of donors: ";
	int donor_num;
	std::cin >> donor_num;
	std::cin.get();
//dynamically alocates memory for donor structures represented as an array
	donorstr * donor = new donorstr [donor_num];


	int grand_patron_num = 0;
	
//loop to request individual donor information and store it in the array
	for (int i = 0; i < donor_num; i++)
		{
		std::cout << "Enter the name of the " << i + 1 << "-th donor: ";
		getline(std::cin, donor[i].name);
		std::cout << "Enter the sum the " << i + 1 << "-th donor has contributed: ";
		std::cin >> donor[i].sum;
		if (donor[i].sum > 10000)
			grand_patron_num++;
		std::cin.get();
		};

//creates 2 new arrays dynamically of two types of donors
	donorstr * Grand_Patrons = new donorstr [grand_patron_num];
	donorstr * Patrons = new donorstr [donor_num - grand_patron_num];
	int grand_i = 0;
	int patron_i = 0;

//copies each donor into one of the two new arrays depending on the amount of money contributed
	for (int i = 0; i < donor_num; i++)
		{
		if (donor[i].sum > 10000)
			{
				Grand_Patrons[grand_i].name = donor[i].name;
				Grand_Patrons[grand_i].sum = donor[i].sum;
				grand_i++;
			}
		else
			{
				Patrons[patron_i].name = donor[i].name;
				Patrons[patron_i].sum = donor[i].sum;
				patron_i++;
			};
		};


//displays Grand Patron list if any
	if (grand_i > 0)
		{
		std::cout << "Grand Patron List\n";
		for (int i = 0; i < grand_i; i++)
			std::cout << Grand_Patrons[i].name << " " << Grand_Patrons[i].sum << std::endl;
		}
	else
		std::cout << "None (Grand Patrons)\n";

//displays Patron list if any
	if (patron_i > 0)
		{
		std::cout << "Patron List\n";
		for (int i = 0; i < patron_i; i++)
			{
			std::cout << Patrons[i].name << " " << Patrons[i].sum << std::endl;
			};
		}
	else
		std::cout << "None (Patrons)\n";
	return 0;
};
