//	Testing the stack data structure
#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
	stack stk;
	cout << "Pushing 3 into stack." << endl;
	stk.push(3);
	cout << "Pushing 5 into stack." << endl;
	stk.push(5);
	cout << "Pushing 2 into stack." << endl;
	stk.push(2);
	cout << endl;
	cout << "Reading stack head: " << stk.read() << endl;
	cout << "Popping item from stack head." << endl;
	stk.pop();
	cout << "Reading stack head: " << stk.read() << endl;
	cout << "Is the stack empty?" << ((stk.isEmpty() == 0) ? "false" : "true") << endl;
	cout << "Popping item from stack head." << endl;
	stk.pop();
	cout << "Popping item from stack head." << endl;
	stk.pop();
	cout << "Is the stack empty?" << ((stk.isEmpty() == 0) ? "false" : "true") << endl;
	//stk.pop();	//	Causes assert fail error.	
}