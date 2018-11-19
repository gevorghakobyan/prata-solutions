//Write a precursor to a menu-driven program.The program should display a menu
//offering four choices, each labeled with a letter. If the user responds with a letter
//other than one of the four valid choices, the program should prompt the user to
//enter a valid response until the user complies.Then the program should use a
//switch to select a simple action based on the user’s selection.

#include <iostream>

//function prototype
void showMenu();

int main(void)
	{
//input character
		char ch;
//calls function
		showMenu();
//prompts to input a character
		std::cin >> ch;
//loop to prompt character input until one of the expected characters is typed
		while (ch)
			{
//switch statement for relevant character input
			switch (ch)
				{
					case 'p': std::cout << "Nikol Pashinyan is the new PM of Armenia."; break;
					case 'm': std::cout << "Maple is a tree not very rare in Armenia."; break;
					case 'a': std::cout << "Aragats is the highest mountain in Armenia."; break;
					case 'c': std::cout << "C++ is the programming language that I am struggling to conquer."; break;
					default: std::cout << "Please enter a, c , m or p: _\b";
				};
// if else statement to break the loop if positive result has been achieved or to prompt new character input otherwise
			if (ch == 'a' || ch == 'c' || ch == 'm' || ch == 'p')
				break;
			else
				std::cin >> ch;
			};
	};

//function definition
void showMenu()
	{
		std::cout << "Please enter one of the following choices:\n"
		"p) prime minister	m)maple\n"
		"a) aragats 		c)c++\n";
	};
