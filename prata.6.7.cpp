/*Write a program that reads input a word at a time until a lone q is entered.The
program should then report the number of words that began with vowels, the num-
ber that began with consonants, and the number that fit neither of those categories.
One approach is to use isalpha() to discriminate between words beginning with
letters and those that don’t and then use an if or switch statement to further iden-
tify those passing the isalpha() test that begin with vowels.A sample run might
look like this:
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others*/

#include <iostream>

//size of the string to take as an input
const int ArSize = 150;

int main(void)
{
//numbers of words starting with vowels, consonants and oterhs
	int vowel = 0;
	int consonant = 0;
	int other_char = 0;

//dynamic array of input string 
	char * str = new char [ArSize];
	std::cout << "Enter words (q to quit): ";
//inputs the words
	std::cin.getline(str, ArSize);

//this loop iterates through the words and counts them accordingly depending what character they start with
	for (int i = 0; i < ArSize; i++)
	{

//if statement checks word start detecting the space before it or if the first word if it's not preceded with a space
		if (str[i] == ' ' || (i == 0 && str[i] != ' '))
		{
//if statement for handling the first word if it's not preceded with a space
			if (i == 0 && str[i] != ' ')
				i = -1;
//if statement to check whether the word starts with a letter
			if (isalpha(str[i + 1]))
			{
//if the input is a lone q, exits the loop
				if (str[i + 1] == 'q' && (str[i + 2] == ' ' || str[i + 2] == '\0'))
				{
					break;
				}
//counting of the words with an initial vowel
				else if (str[i + 1] == 'a' || str[i + 1] == 'A' || str[i + 1] == 'e' || str[i + 1] == 'E' || str[i + 1] == 'i' || str[i + 1] == 'I' || str[i + 1] == 'o' || str[i + 1] == 'O' || str[i + 1] == 'u' || str[i + 1] == 'U' || str[i + 1] == 'y' || str[i + 1] == 'Y')
				{
					vowel++;
				}
//counts the words with initial consonant
				else
				{
					consonant++;
				};
			}
//counts the words starting with anything but a letter
			else
			{
				other_char++;
			};
//if statement in case the first word has not been preceded with a space: earlier some shifts have been made which are now beeing unsettled
			if (i == -1)
				i = 0;
		};
	};

//displays number of words starting with different initial characters
	std::cout << vowel << " words beginning with vowels.\n" << consonant << " words beginning with consonants.\n" << other_char << " others.\n";
	return 0;
};
