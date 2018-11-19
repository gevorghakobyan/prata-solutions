#ifndef _prata_15_1_h_
#define _prata_15_1_h_

#include <stdexcept>
#include <iostream>
#include <cmath>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean() : std::logic_error("logic error") {};
	const char * what() { return "problem in hmean function - one number can be the negative of the other\n"; };
};


class bad_gmean : public std::logic_error
{
public:
	bad_gmean() : std::logic_error("logic error") {};
	const char * what() { return "problem in gmean function - neither of the numbers can be negative\n"; };
};

#endif
