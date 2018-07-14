/*Enhance the String class declaration (that is, upgrade string1.h to string2.h ) by
doing the following:
a. Overload the + operator to allow you to join two strings into one.
b. Provide a stringlow() member function that converts all alphabetic charac-
ters in a string to lowercase. (Don’t forget the cctype family of character
functions.)
c. Provide a stringup() member function that converts all alphabetic charac-
ters in a string to uppercase.
d. Provide a member function that takes a char argument and returns the num-
ber of times the character appears in the string.
Try your work in the following program: (which is in main function at present)
*/

#include <iostream>
#include <cstring>
#include <cctype>

//prototype ---------------------------------------

class String
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char * s);
	String();
	String(const String &);
	~String();
	int length () const {return len;};
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	char * operator+(String const & st);
	char * operator+(char const * ch);
	String * stringlow();
	String * stringup();
	friend char * operator+(char const * ch, String const & st);
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream & operator>>(std::istream & is, String & st);
	static int HowMany();
	int has(char ch);
};

//main --------------------------------------------

int main()
{
	String s1(" and I am a c++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	std::cout << s2;
	std::cin >> s3;
	s2 = "My name is  " + s3;
	std::cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	std::cout << "The string\n" << s2 << "\ncontains " << s2.has ('A') << " 'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String ("blue")};
	std::cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (std::cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])
			{
				std::cout << "That's right!\n";
				success = true;
				break;
			};
		};
		if (success)
		{
			break;
		}
		else
		{
			std::cout << "Try again!\n";
		};
	};
	std::cout << "Bye \n";



	return 0;
};

//definitions -------------------------------------
int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
};

String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	++num_strings;
};

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	++num_strings;
};

String::String(const String & st)
{
	++num_strings;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
};

String::~String()
{
	--num_strings;
	delete [] str;
};

String & String::operator=(const String & st)
{
	if (this == &st)
	{
		return * this;
	};
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
};

String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return * this;
};

char & String::operator[](int i)
{
	return str[i];
};

const char & String::operator[](int i) const
{
	return str[i];
};

char * String::operator+(const String & st)
{
	char * s = new char[len + st.len + 1];
	std::strcpy(s, str);
	std::strcat(s, st.str);
	return s;
};

char * String::operator+(char const * ch)
{
	char * s = new char[len + std::strlen(ch) + 1];
	std::strcpy(s, str);
	std::strcat(s, ch);
	return s;
};

char * operator+(char const * ch, String const & st)
{
	char * s = new char [std::strlen(ch) + st.len ];
	std::strcpy(s, ch);
	std::strcat(s, st.str);
	return s;
};

String * String::stringlow()
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		str[i] = static_cast<char>(std::tolower(str[i]));
	};
	return this;
};

String * String::stringup()
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		str[i] = static_cast<char>(std::toupper(str[i]));
	};
	return this;
};

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
};

bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
};

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
};

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
};

std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
	{
		st = temp;
	};
	while (is && is.get() != '\n')
	{
		continue;
	};
	return is;
};

int String::has(char ch)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == ch)
		{
			++count;
		};
	};
	return count;
};
