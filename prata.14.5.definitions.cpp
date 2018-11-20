#include "prata.14.5.h"

abstr_emp::abstr_emp() : fname("charming"), lname("lady"), job("housewife")
{
};

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) : fname(fn), lname(ln), job(j)
{
};

abstr_emp::abstr_emp(const abstr_emp & e)
{
	fname = e.fname;
	lname = e.lname;
	job = e.job;
};

void abstr_emp::ShowAll() const
{
	std::cout <<
	"First name: " << fname << std::endl << 
	"Last name :" << lname << std::endl <<
	"Job: " << job << std::endl;
};

void abstr_emp::SetAll()
{
	std::cout << "First name? ";
	std::cin >> fname;
	std::cout << "Last name? ";
	std::cin >> lname;
	std::cout << "Job? ";
	std::cin >> job;
};

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	e.ShowAll();
	return os;
};

abstr_emp::~abstr_emp()
{
};

employee::employee() : abstr_emp()
{
};

employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j)
{
};

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
};

void employee::SetAll()
{
	abstr_emp::SetAll();
	std::cout << std::endl;
};

manager::manager() : abstr_emp(), inchargeof(0)
{
};

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
};

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico)
{
};

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
};

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "In charge of " << InChargeOf() << " employees." << std::endl;
};

void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "In charge of how many? ";
	std::cin >> inchargeof;
	std::cout << std::endl;
};

fink::fink() : abstr_emp(), reportsto("nobody")
{
};

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
};

fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo)
{
};

fink::fink(const fink & e) : abstr_emp(e)
{
	reportsto = e.reportsto;
};

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Reports to "<< ReportsTo() << std::endl;
};

void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Whom does report? ";
	std::cin >> reportsto;
	std::cout << std::endl;
};

highfink::highfink() : abstr_emp(), manager(), fink()
{
};

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico) : abstr_emp(fn, ln, j)
{
ReportsTo() = rpo;
InChargeOf() = ico;
};

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e)
{
	ReportsTo() = rpo;
	InChargeOf() = ico;
};

highfink::highfink(const fink & f, int ico) : abstr_emp(f), fink(f)
{
	InChargeOf() = ico;
};

highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m)
{
	ReportsTo() = rpo;
};

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h)
{
};

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "In charge of " << InChargeOf() << " employees." << std::endl;
	std::cout << "Reports to " << ReportsTo() << std::endl;
};

void highfink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "In charge of how many? ";
	std::cin >> InChargeOf();
	std::cout << "Whom does report? ";
	std::cin >> ReportsTo();
	std::cout << std::endl;
};

