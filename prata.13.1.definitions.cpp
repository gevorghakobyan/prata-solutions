#include "prata.13.1.h"

Cd::Cd() : selections(0), playtime(0)
{
	std::strcpy(performance, "no performance");
	std::strcpy(label, "no label");
};

Cd::~Cd()
{
};

Cd::Cd(const char * s1, const char * s2, int n, double x) : selections(n), playtime(x)
{
	int j = (std::strlen(s1) < 49 ? std::strlen(s1) : 49);
	for (int i = 0; i < j; ++i)
	{
		performance[i] = s1[i];
	};
	performance[j] = '\0';
	j = (std::strlen(s2) < 19 ? std::strlen(s2) : 19);
	for (int i = 0; i < j; ++i)
	{
		label[i] = s2[i];
	};
	label[j] = '\0';
	
};

Cd::Cd(const Cd & d) : selections(d.selections), playtime(d.playtime)
{	
	std::strcpy(performance, d.performance);
	std::strcpy(label, d.label);
};

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
	{
		return *this;
	};
	std::strcpy(performance, d.performance);
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
	std::strcpy(primary, "no primary");
}

Classic::~Classic()
{
};

Classic::Classic(const char * s3, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	int j = (std::strlen(s3) < 49 ? std::strlen(s3) : 49);
	for (int i = 0; i < j; ++i)
	{
		primary[i] = s3[i];
	};
	primary[j] = '\0';
};

Classic::Classic(const Classic & c) : Cd(c)
{
	std::strcpy(primary, c.primary);
};

Classic & Classic::operator=(const Classic & c)
{
	if (this == &c)
	{
		return *this;
	};
	Cd::operator=(c);
	std::strcpy(primary, c.primary);
	return *this;
};

void Classic::Report() const
{
	this->Cd::Report();
	std::cout << "Primary: " << primary << std::endl;
};
