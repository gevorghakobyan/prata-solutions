/*Provide the implementation for this class and write a short program that uses all the
member functions.
*/


#include <iostream>
#include <cstring>

//prototypes ------------------------------------------------------------------
class Cow
{
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c); 
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const; //display all cow data
};


//main -----------------------------------------------------------------------
int main()
{
	Cow Jack;
	Cow John("John", "tourism", 194.6);
	Cow Jill = John;
	Jack = John;
	John.ShowCow();
	Jill.ShowCow();
	Jack.ShowCow();
	return 0;
};


//definitions ----------------------------------------------------------------
Cow::Cow()
{
	std::cout << "default constructor called" << std::endl;
	std::strcpy(name, "no name");
	hobby = new char[9];
	std::strcpy(hobby, "no hobby");
	weight = 0;	
};

Cow::Cow(const char * nm, const char * ho, double wt)
{
	std::cout << "parameterized constructor called" << std::endl;
	std::strcpy(name, nm);
	hobby = new char[std::strlen(ho) + 1];
	std::strcpy(hobby, ho);
	weight = wt;		
};

Cow::Cow(const Cow & c) 
{
	std::cout << "copy constructor called" << std::endl;
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
};

Cow::~Cow()
{
	std::cout << "default constructor called" << std::endl;
	delete hobby;
};

Cow & Cow::operator=(const Cow & c)
{
	std::cout << "assignment operator called" << std::endl;
	if (this == &c)
	{
		return *this;
	};
	delete hobby;
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
};

void Cow::ShowCow() const
{
	std::cout << "cow name: " << name << std::endl;
	std::cout << "cow hobby: " << hobby << std::endl;
	std::cout << "cow weight: " << weight << std::endl;
};
