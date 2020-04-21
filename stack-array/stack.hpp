//	Stack definition
#ifndef STACK_H
#define STACK_H

#include "node.hpp"

const int MAX_SIZE = 100;

class stack {
	friend void printStack(stack& stk);
	
public:
	stack();
	~stack();
	
	//	Operators
	void init();
	bool isEmpty() const;
	void push(data_type);
	void pop();
	data_type read() const;
	
private:
	node contents[MAX_SIZE];
	int head;
};

#endif // !STACK_H