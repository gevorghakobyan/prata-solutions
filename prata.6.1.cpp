//Write a program that reads keyboard input to the @ symbol and that echoes the
//input except for digits, converting each uppercase character to lowercase, and vice
//versa. (Don’t forget the cctype family.)

#include <iostream>
#include <cctype>

int main(void)
{
	char ch;
	std::cout << "Enter something: _\b";

//loop to read the input until @ is enter or EOF
	while (std::cin.get(ch) && ch != '@')
	{

//if statement to the job only when the input in a non-digit
		if (!(std::isdigit(ch)))
		{

//if statement to lowercase the letters (if uppercase is entered),
//uppercase (if the letter is lowercase) and print unchanged if the input is not a letter
			if (std::isupper(ch))
			{
				std::cout << (char) std::tolower(ch);
			}
			else if (std::islower(ch))
			{
				std::cout << char (std::toupper(ch));
			}
			else 
			{
				std::cout << ch;
			};
		};
	};


	return 0;
};
