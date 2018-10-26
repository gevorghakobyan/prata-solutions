#include "prata.13.2.h"

Cd::Cd() : selections(0), playtime(0)
{
	performance = new char[std::strlen("no performance")];
	std::strcpy(performance, "no performance");
	label = new char[std::strlen("no label")];
	std::strcpy(label, "no label");
};

Cd::~Cd()
{
	delete [] performance;
	delete [] label;
};

Cd::Cd(const char * s1, const char * s2, int n, double x) : selections(n), playtime(x)
{
	performance = new char[std::strlen(s1)];
	std::strcpy(performance, s1);
	label = new char[std::strlen(s2)];
	std::strcpy(label, s2);	
};

Cd::Cd(const Cd & d) : selections(d.selections), playtime(d.playtime)
{	
	performance = new char[std::strlen(d.performance)];
	std::strcpy(performance, d.performance);
	label = new char[std::strlen(d.label)];
	std::strcpy(label, d.label);
};

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
	{
		return *this;
	};
	delete [] performance;
	performance = new char[std::strlen(d.performance)];
	std::strcpy(performance, d.performance);
	delete [] label;
	label = new char[std::strlen(d.label)];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
};

void Cd::Report() const
{
	std::cout << "Performance: " << performance << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
};

// Classic ================================================

Classic::Classic() : Cd()
{
	primary = new char[std::strlen("no primar")];
	std::strcpy(primary, "no primary");
}

Classic::~Classic()
{
	delete [] primary;
};

Classic::Classic(const char * s3, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	primary = new char[std::strlen(s3)];
	std::strcpy(primary, s3);
};

Classic::Classic(const Classic & c) : Cd(c)
{
	primary = new char[std::strlen(c.primary)];
	std::strcpy(primary, c.primary);
};

Classic & Classic::operator=(const Classic & c)
{
	if (this == &c)
	{
		return *this;
	};
	Cd::operator=(c);
	delete [] primary;
	primary = new char[std::strlen(c.primary)];
	std::strcpy(primary, c.primary);
	return *this;
};

void Classic::Report() const
{
	this->Cd::Report();
	std::cout << "Primary: " << primary << std::endl;
};

