#ifndef _prata_13_1_h_
#define _prata_13_1_h_

#include <iostream>
#include <cstring>

class Cd
{
private:
	char performance[50];
	char label[20];
	int selections; //number of selections
	double playtime; // playing time in minutes
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	~Cd();
	virtual void Report() const; // reports all CD data
	Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char primary[50];
public:
	Classic();
	~Classic();
	Classic(const char * s3, const char * s1, const char * s2, int n, double x);
	Classic(const Classic & c);
	Classic & operator=(const Classic & c);
	virtual void Report() const;
};


#endif
