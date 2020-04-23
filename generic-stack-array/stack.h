#//	Generic stack data structure
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>

template<class T>
class stack {
	//	Has access to the stack's private member in
	//	order to print it without popping the contents.
	friend void printStack(stack& stk) {
		using namespace std;

		for (int i = 0; i < stk.head; i++)
			cout << stk.contents[i] << ' ';

		cout << endl;
	}

public:
	typedef T data_type;
	
	//	Constructors
	stack();
	stack(int);
	~stack();
	
	//	Operators
	void init();
	bool isEmpty() const;
	data_type read() const;
	void push(data_type);
	void pop();
	
private:
	data_type* contents;
	int capacity;
	int head;
};

template<class T>
stack<T>::stack() {
	capacity = 100;
	contents = new data_type[capacity];
	init();
}

template<class T>
stack<T>::stack(int n) {
	capacity = n;
	contents = new data_type[capacity];
	init();
}

template<class T>
stack<T>::~stack() { delete[] contents; }

template<class T>
void stack<T>::init() { head = 0; }

template<class T>
bool stack<T>::isEmpty() const { return head == 0; }

template<class T>
typename stack<T>::data_type stack<T>::read() const { return contents[head - 1]; }

template<class T>
void stack<T>::pop() {
	if (!isEmpty())
		head -= 1;
}

template<class T>
void stack<T>::push(data_type d) {
	assert(head != capacity);
	contents[head] = d;
	head++;
}

#endif // !STACK_H