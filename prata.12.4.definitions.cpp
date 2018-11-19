#include "prata.12.4.h"

Stack::Stack(int n) : size(n), top(0)
{
	pitems = new Item[size];
};

Stack::Stack(const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < top; ++i)
	{
		pitems[i] = st.pitems[i];
	};
};

Stack::~Stack()
{
	delete [] pitems;
};

bool Stack::isempty() const
{
	return top == 0;
};

bool Stack::isfull() const
{
	return top == size;
};

bool Stack::push(const Item & item)
{
        if (isfull())
        {
                return false;
        }
        else
        {
                pitems[top++] = item;
                return true;
        };
};

bool Stack::pop()
{
        if (isempty())
        {
                return false;
        }
        else
        {
                --top;
                return true;
        };
};

Stack & Stack::operator=(const Stack & st)
{
	if (this == &st)
	{
		return *this;
	};

	delete [] pitems;
	size = st.size;
	top = st.top;
	pitems = new Item[size];

	for (int i = 0; i < top; ++i)
	{
		pitems[i] = st.pitems[i];
	};

	return *this;	
};
