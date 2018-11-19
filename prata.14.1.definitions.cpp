#include "prata.14.1.h"

template<class T1, class T2>
T1 & Pair<T1, T2>::first()
{
	return a;
};

template<class T1, class T2>
T2 & Pair<T1, T2>::second()
{
	return b;
};

Wine::Wine() : name("no name"), year_num(0), pair(ArrayInt(year_num), ArrayInt(year_num))
{	
};

Wine::Wine(const char * l, int y) : name(l), year_num(y), pair(ArrayInt(year_num), ArrayInt(year_num))
{
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : name(l), year_num(y), pair(ArrayInt(yr, year_num), ArrayInt(bot, year_num))
{
};

void Wine::GetBottles()
{
	std::cout << "Enter " << Label() << " data for " << year_num << " year(s):" << std::endl;
	for (int i = 0; i < year_num; ++i)
	{
		std::cout << "Enter year: ";
		std::cin >> pair.first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> pair.second()[i];
	};
};

int Wine::sum()
{
	int sum = 0;
	for (int i = year_num - 1; i > -1; --i)
	{
		sum += pair.second()[i];
	};
	return sum;
};

std::string Wine::Label()
{
	return name;
};

void Wine::Show()
{
	std::cout << "Wine: \t " << Label() << std::endl;
	std::cout << "Year\tBottles\n";
	for (int i = 0; i < year_num; ++i)
	{
		std::cout << "\t" << pair.first()[i] << "\t" << pair.second()[i] << std::endl;
	};
};
