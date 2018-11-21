#include <iostream>
#include <string>
#include <cctype>

bool IsPalindrome(std::string & str);

int main()
{
	std::string input;
	std::cout << "Enter a string: ";
	getline(std::cin, input);

	std::cout << "The string is palindrome: " << std::boolalpha << IsPalindrome(input) << std::endl;

	return 0;
};

bool IsPalindrome(std::string & str)
{
	std::string alpha_str;
	for (char x : str)
	{	
		if (isalpha(x))
		{
			alpha_str += tolower(x);
		};
	};

	str = {alpha_str.begin(), alpha_str.end()}; 
	std::string back_str {alpha_str.rbegin(), alpha_str.rend()};
	return str == back_str;
};
