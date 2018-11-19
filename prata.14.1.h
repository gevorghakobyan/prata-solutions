#ifndef _prata_14_1_h_
#define _prata_14_1_h_
#include <iostream>
#include <string>
#include <valarray>

typedef std::valarray<int> ArrayInt;

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; };
	T2 second() const { return b; };
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { };
	Pair() {};
};

typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	std::string name;
	int year_num;
	PairArray pair;
public:
	Wine();
	Wine(const char * l, int y);
	Wine(const char * l, int y, const int yr[], const int bot[]);
	void GetBottles();
	int sum();
	std::string Label();
	void Show();
};

#endif
