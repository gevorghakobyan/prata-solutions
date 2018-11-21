#include <iostream>
#include <string>

bool IsPalindrome(std::string & str);

int main()
{
	std::string input;
	std::cout << "Enter the string: ";
	getline(std::cin, input);
	bool is_palindrome = IsPalindrome(input);
	std::cout << std::boolalpha << is_palindrome << std::endl;


	return 0;
};

bool IsPalindrome(std::string & str)
{
	std::string back_str {str.rbegin(), str.rend()};
	return str == back_str;
};
