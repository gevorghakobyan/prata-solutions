#ifndef _prata_15_3_h_
#define _prata_15_3_h_

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>

class bad_mean : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	bad_mean(double a = 0, double b = 0);
	virtual const char * what();
};

class bad_hmean : public bad_mean
{
public:
	bad_hmean(double a = 0, double b = 0);
	const char * what();
};

class bad_gmean : public bad_mean
{
public:
	bad_gmean(double a = 0, double b = 0);
	const char * what();
};

bad_mean::bad_mean(const double a, const double b) : std::logic_error("problem"), v1(a), v2(b)
{
};

bad_hmean::bad_hmean(double a, double b) : bad_mean(a, b)
{
};

const char * bad_mean::what()
{
	std::cout << "values are: " << v1 << ", " << v2 << ". ";
	return "problem in mean";
};

bad_gmean::bad_gmean(double a, double b) : bad_mean(a, b)
{
};

const char * bad_hmean::what()
{
	bad_mean::what();
	return "problem in hmean.";
};

const char * bad_gmean::what()
{
	bad_mean::what();
	return "problem in gmean.";
};

#endif
