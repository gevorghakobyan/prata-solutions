/*When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name.Write a pro-
gram that can list members by real name, by job title, by secret name, or by a mem-
ber’s preference. Base the program on the following structure:
// Benevolent Order of Programmers name structure
struct bop {
char fullname[strsize]; // real name
char title[strsize];
// job title
char bopname[strsize]; // secret BOP name
int preference;
// 0 = fullname, 1 = title, 2 = bopname
};
In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alterna-
tives:
a. display by name
c. display by bopname
q. quit
b. display by title
d. display by preference
301302
Chapter 6 Branching Statements and Logical Operators
Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is 1 , choice d would display the programmer’s job title.A sample run
may look something like the following:
Benevolent Order of Programmers Report
a. display by name
b. display by title
c. display by bopname d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!*/

#include <iostream>

int main(void)
{

//bop structure
	struct bop {
		char fullname[30];
		char title[15];
		char bopname[15];
		int preference;
	};

//initializing a bop type array of 3 elements
	bop programmers[3] = {{"John Smith", "junior", "SMITHY", 1}, {"Charlotte Bronte", "middle", "Jane", 3}, {"Rolland Graham", "senior", "BIG ROLL", 2}};

//prints the choices to select from
	std::cout << "Benevolent Order of Programmers Report\n",
		"a.display by name		b.display by title\n",
		"c.display by bopname	d.display by preference\n",
		"q.quit\n";
	std::cout << "Enter your choice: _\b";

//char type variable to hold the choice
	char ch;
//gets the first choice value
	std::cin >> ch;
//loop to request choices, display results or exit the program
	while (ch)
		{
//quits the program
			if (ch == 'q')
				{
				std::cout << "BYE";
				break;
				};

//switch statement to display results relevant for each choice
			switch (ch)
				{
//prints full names
					case 'a':
						for (int i = 0; i < 3; i++)
							{
							std::cout << programmers[i].fullname << std::endl;
							};
						break;
//prints titles
					case 'b':
						for (int i = 0; i < 3; i++)
							{
							std::cout << programmers[i].title << std::endl;
							};
						break;
//prints bop names
					case 'c':
						for (int i = 0; i < 3; i++)
							{
							std::cout << programmers[i].bopname << std::endl;
							};
							break;
//prints according to members preference
					case 'd':
						for (int i = 0; i < 3; i++)
							{
//switch statement to initilize what each preference integer implies: 0 for fullname, 1 for title and 2 for bopname
								switch (programmers[i].preference)
									{
										case 0:
											std::cout << programmers[i].fullname << std::endl;
										case 1:
											std::cout << programmers[i].title << std::endl;
										case 2:
											std::cout << programmers[i].bopname << std::endl;
									};
							};

				};
//requests a new choice since the user hasn't quit the program yet
			std::cout << "Next choice: _\b";
			std::cin >> ch;
		};

	return 0;
};
