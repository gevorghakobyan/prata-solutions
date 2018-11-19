#include "prata.12.4.h"
#include <iostream>

int main()
{
	Stack a(3);
	std::cout << "A stack of size 3 is created." << std::endl;
	std::cout << "Stack empty: " << a.isempty() << std::endl;
	std::cout << "Stack full: " << a.isfull() << std::endl;
	std::cout << "Pushing an item into the stack: " << a.push(2) << std::endl;

	std::cout << "Stack empty: " << a.isempty() << std::endl;
	std::cout << "Stack full: " << a.isfull() << std::endl;
	std::cout << "Another item pushed to the stack: " << a.push(3) << std::endl;
	std::cout << "Third item added to the stack: " << a.push(8) << std::endl;
	std::cout << "Stack empty: " << a.isempty() << std::endl;
	std::cout << "Stack full: " << a.isfull() << std::endl;
	std::cout << "Trying to force extra item to the stack: " << a.push(1) << std::endl;
	std::cout << "Popping an item: " << a.pop() << std::endl;
	std::cout << "Copy-constructing a second stack. " << std::endl;
	Stack b(a);
	std::cout << "Adding an item to the second stack: " << b.push(7) << std::endl;
	std::cout << "Second stack full: " << b.isfull() << std::endl;
	std::cout << "Creating a third stack." << std::endl;
	Stack c;
	std::cout << "First stack is being copy-assigned to the third stack: " << std::endl;
	c = a;
	std::cout << "Adding last item to the third stack: " << c.push(10) << std::endl;
	std::cout << "Third stack empty: " << c.isempty() << std::endl;
	std::cout << "Third stack full: " << c.isfull() << std::endl;
	
	return 0;
};
