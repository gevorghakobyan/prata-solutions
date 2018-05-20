/*Write a function that normally takes one argument, the address of a string, and
prints that string once. However, if a second, type int , argument is provided and is
nonzero, the function should print the string a number of times equal to the num-
ber of times that function has been called at that point. (Note that the number of
times the string is printed is not equal to the value of the second argument; it isProgramming Exercises
equal to the number of times the function has been called.) Yes, this is a silly func-
tion, but it makes you use some of the techniques discussed in this chapter. Use the
function in a simple program that demonstrates how the function works.*/

#include <iostream>

void display(const char * str, int num = 0);

//number - how many times has been the function called
int count = 0;


int main(void)
{	
	char str[] = "I'm a fucking lucky son of a beach!";
	display(str, 5);
	std::cout << std::endl;
	display(str, 3);
	std::cout << std::endl;
	display(str);
	std::cout << std::endl;
	display(str, 1);
	return 0;
};


//displaying function definition
void display(const char * str, int num)
{	
	count++;
	if (num == 0)
		std::cout << str << std::endl;
	if (num != 0)
	{
		for (int i = 0; i < count; i++)
			std::cout << str << std::endl;
	};
};
