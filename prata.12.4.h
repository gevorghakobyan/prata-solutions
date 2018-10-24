#ifndef _prata_12_4_h_
#define _prata_12_4_h_

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};
	Item * pitems;
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop();
	Stack & operator=(const Stack & st);
};

#endif
