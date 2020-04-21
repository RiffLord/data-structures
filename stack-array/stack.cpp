#include <iostream>
#include <assert.h>
#include "stack.hpp"

stack::stack() { init(); }

stack::~stack() {}

//	Operators

void stack::init() { 
	for (int i = 0; i < MAX_SIZE; i++) contents[i].setItem(0);
	head = 0; 
}

bool stack::isEmpty() const { return head == 0; }

data_type stack::read() const { return contents[head - 1].getItem(); }

void stack::pop() {
	assert(!isEmpty());
	head -= 1;
}

void stack::push(data_type d) {
	assert(head != MAX_SIZE);
	contents[head].setItem(d);
	head++;
}

void printStack(stack& stk) {
	for (int i = 0; i < stk.head; i++)
		std::cout << stk.contents[i] << ' ';
		
	std::cout << std::endl;
}