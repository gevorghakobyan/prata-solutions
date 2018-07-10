#include <iostream>
#include <cctype>

int char_to_int(char ch[]);

int main(void)
{
	char exp[20];
	std::cout << "Enter the expression to count: ";
	std::cin >> exp;

	char num1[8];
	char op[1];
	char num2[8];
	int i = 0;
	for (int j = 0; isdigit(exp[i]); i++, j++)
		num1[j] = exp[i];
	op[0] = exp[i];
	i++;
	for (int j = 0; isdigit(exp[i]); i++, j++)
		num2[j] = exp[i];

	int num_1 = char_to_int(num1);
	int num_2 = char_to_int(num2);
	
	int result = 0;
	switch (op[0])
	{
		case '*': result = num_1 * num_2; break;
		case '/': result = num_1 / num_2; break;
		case '+': result = num_1 + num_2; break;
		case '-': result = num_1 - num_2; break;
		default: std::cout << "No result.";
	};
	std::cout << result << std::endl;
	
	return 0;
};

//function that receives a series of char(numerals) and outputs an integer
int char_to_int(char ch[])
{
	int num = 0;
	for (int i = 0; ch[i] != '\0'; i++)
		num = num * 10 + int (ch[i] - '0');
	return num;
};

			
