#include "prata.11.7.h"

Complex::Complex()
{
	m_real = m_imagine = 0;
};

Complex::~Complex()
{
};

Complex::Complex(double real, double imagine)
{
	m_real = real;
	m_imagine = imagine;
};

Complex Complex::operator+(const Complex & cmp) const
{
	return Complex(m_real + cmp.m_real, m_imagine + cmp.m_imagine);
};

Complex Complex::operator-(const Complex & cmp) const
{
	return Complex(m_real - cmp.m_real, m_imagine - cmp.m_imagine);
};

Complex Complex::operator*(const Complex & cmp) const
{
	return Complex(m_real * cmp.m_real - m_imagine * cmp.m_imagine, m_real * cmp.m_imagine + m_imagine * cmp.m_real);
};

Complex Complex::operator*(const double d) const
{
	return Complex(d * m_real, d * m_imagine);
};

Complex Complex::operator~() const
{
	return Complex(m_real, 0 - m_imagine);
};

std::istream & operator>>(std::istream & is, Complex & cmp)
{
	std::cout << "real: ";
	is >> cmp.m_real;
	std::cout << "imaginary: ";
	is >> cmp.m_imagine;
	return is;
};

std::ostream & operator<<(std::ostream & os, const Complex & cmp)
{
	os << "(" << cmp.m_real << ", " << cmp.m_imagine << "i);";
};

Complex operator*(double d, const Complex & cmp)
{
	return Complex(d * cmp.m_real, d * cmp.m_imagine);
};
