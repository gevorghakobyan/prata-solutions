/*Rewrite the Stonewt class (Listings 11.17 and 11.17) so
 thah it has  state member that governs whether the object is
 interpreted in stone form, integer pounds form, or floating-
point pounds form. Overload the << operator to replace the 
show_stn() and show_lbs() methods. Overload the addition,
subraction, and multiplication operators so that one can add,
 subtract, and multiply Stonewt values. Test your class with 
a short program that uses all the class methods and friends.*/


#include <iostream>

//prototypes ------------------------------------------------


class Stonewt
{
public:
	enum Mode {STONE, LBS, FLOAT_LBS};
private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
	Mode _MODE;
public:
	Stonewt(double lbs, Mode mode = FLOAT_LBS);
	Stonewt(int stn, double lbs, Mode mode = LBS);
	Stonewt();
	~Stonewt();
	friend std::ostream & operator<<(std::ostream & os, const Stonewt & sw);
	Stonewt operator+(Stonewt const & rhs);
	Stonewt operator+(double pound);
	friend Stonewt operator+(double pound, Stonewt & rhs);
	Stonewt operator-(Stonewt const & rhs);
	Stonewt operator-(double pound);
	friend Stonewt operator-(double pound, Stonewt const & rhs);
	Stonewt operator*(double mult);
	friend Stonewt operator*(double mult, Stonewt const & rhs);
};


//main ------------------------------------------------------
int main()
{
	Stonewt weight(104.5);
	Stonewt new_weight = (94.8);
	std::cout << weight;
	std::cout << new_weight;
	std::cout << weight + new_weight;
	std::cout << weight + 10.3;
	std::cout << 10.3 + weight;
	std::cout << weight - new_weight;
	std::cout << new_weight - weight;
	std::cout << weight - 100;
	std::cout << weight - 110;
	std::cout << 110 - weight;
	std::cout << 100 - weight;
	std::cout << weight * 2;
	std::cout << 3 * weight;
	return 0;
};


//definitions -----------------------------------------------
Stonewt::Stonewt(double lbs, Mode mode)
{
	_MODE = mode;
	stone = int (lbs) / Lbs_per_stn;
	pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
	pounds = lbs;
};


Stonewt::Stonewt(int stn, double lbs, Mode mode)
{
	_MODE = mode;
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
};


Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	_MODE = LBS;
};


Stonewt::~Stonewt()
{
};


std::ostream & operator<<(std::ostream & os, const Stonewt & sw)
{
	if (sw._MODE == Stonewt::STONE)
	{
		os << sw.stone << " stones." << std::endl;
	}
	else if (sw._MODE == Stonewt::LBS)
	{
		os << int (sw.pounds) << " whole pounds." << std::endl;
	}
	else
	{
		os << sw.pounds << " pounds." << std::endl;
	};
};


Stonewt Stonewt::operator+(Stonewt const & rhs)
{
	return Stonewt(this->pounds + rhs.pounds);
};


Stonewt Stonewt::operator+(double pound)
{
	return Stonewt(this->pounds + pound);
};


Stonewt operator+(double pound, Stonewt & rhs)
{
	return rhs + pound;
};


Stonewt Stonewt::operator-(Stonewt const & rhs)
{
	return (pounds >= rhs.pounds) ? Stonewt(this->pounds - rhs.pounds) : Stonewt(0);
};


Stonewt Stonewt::operator-(double pound)
{
	return (pounds >= pound) ? Stonewt(pounds - pound) : Stonewt(0);
};


Stonewt operator-(double pound, Stonewt const & rhs)
{
	return (pound >= rhs.pounds) ? Stonewt(pound - rhs.pounds) : Stonewt(0);
};


Stonewt Stonewt::operator*(double mult)
{
	return Stonewt(pounds * mult);
};


Stonewt operator*(double mult, Stonewt const & rhs)
{
	return Stonewt(mult * rhs.pounds);
};
