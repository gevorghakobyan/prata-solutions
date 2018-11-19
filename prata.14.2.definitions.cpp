#include "prata.14.2.h"

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

Wine::Wine() : name("no name"), year_num(0), PairArray(ArrayInt(0), ArrayInt(0))
{	
};

Wine::Wine(const char * l, int y) : name(l), year_num(y), PairArray(ArrayInt(year_num), ArrayInt(year_num))
{
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), name(l), year_num(y)
{
};

void Wine::GetBottles()
{
	std::cout << "Enter " << Label() << " data for " << year_num << " year(s):" << std::endl;
	for (int i = 0; i < year_num; ++i)
	{
		std::cout << "Enter year: ";
		std::cin >> first()[i];
		std::cout << "Enter bottles for that year: ";
		std::cin >> second()[i];
	};
};

int Wine::sum()
{
	int sum = 0;
	for (int i = year_num - 1; i > -1; --i)
	{
		sum += second()[i];
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
		std::cout << "\t" << first()[i] << "\t" << second()[i] << std::endl;
	};
};
