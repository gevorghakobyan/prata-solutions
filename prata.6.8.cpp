//Write a program that opens a text file, reads it character-by-character to the end of
//the file, and reports the number of characters in the file.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(void)
{
//char variable for characters to be exported from the file and displayed
	char ch;
//number of characters
	int count = 0;
//defines fin object for file
	std::ifstream fin;
//string for storing file name to be processed
	std::string file_name;
	std::cout << "Enter the text file name: ";
//gets file name
	std::getline(std::cin, file_name);

//opens the file
	fin.open(file_name);
//if statement to display the contents of the file if file has been opened successfully or exit otherwise
	if (fin.is_open())
	{
//while loop for iterating over all characters in the file, displaying and counting them
		while (!(fin.fail()))
		{
			fin.get(ch);
			std::cout << ch;
			count++;
		};
//closes the file
		fin.close();		
	}
//else statement to handle the process in case file couldn't be opened
	else
	{
		std::cout << "File couldn't be opened.";
		std::exit(EXIT_FAILURE);
	};
//displays the number of character in the file
	std::cout << "Character count: " << count;
	return 0;
};
