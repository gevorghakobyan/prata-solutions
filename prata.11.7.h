#ifndef prata_11_7_h_
#define prata_11_7_h_

#include <iostream>

class Complex
{
private:
	double m_real;
	double m_imagine;
public:
	Complex();
	~Complex();
	Complex(double real, double imagine);
	Complex operator+(const Complex & cmp) const;
	Complex operator-(const Complex & cmp) const;
	Complex operator*(const Complex & cmp) const;
	Complex operator*(const double d) const;
	Complex operator~() const;
	friend Complex operator*(double d, const Complex & cmp);
	friend std::istream & operator>>(std::istream & is, Complex & cmp);
	friend std::ostream & operator<<(std::ostream & os,const Complex & cmp);
};


#endif
