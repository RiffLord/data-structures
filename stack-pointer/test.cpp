#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std; 

//	WARNING: only supports single-digit operands

void evaluatePostfix(char*);
void convertToRPN(char*);
bool isPalindrome(char*);

//	Evaluating a postfix notation expression 
//	provided from the command line.
//	Example expression: 598+46**7+* = 2075
int main(int argc, char* argv[]) {	
	char* postfExpression = argv[1];
	char* infExpression = argv[2];
	char* palin = argv[3];

	evaluatePostfix(postfExpression);
	convertToRPN(infExpression);
	cout << endl << "Is " << palin << " a palindrome? " 
		 << ((isPalindrome(palin)) ? "true" : "false") << endl;

	return 0;
}

void evaluatePostfix(char* expression) {
	int expLength = strlen(expression);
	stack<int> postfix;

	int currentItem;
	int previousItem;

	cout << "Evaluating: " << expression << endl;
	cout << endl;

	for (int i = 0; i < expLength; ++i) {
		//	Pushes numbers into the stack
		if ((expression[i] >= '0') && (expression[i] <= '9'))
			postfix.push(expression[i] - '0');	//	Converts ASCII digits between 0 and 9 into the corresponding integers

		//	For each operation, pops the previous two elements of the stack
		//	to use as operands and pushes the result of the operation back in.
		if (expression[i] == '+') {
			currentItem = postfix.read();
			postfix.pop();
			previousItem = postfix.read();
			postfix.pop();
			postfix.push(currentItem + previousItem);
		}

		if (expression[i] == '*') {
			currentItem = postfix.read();
			postfix.pop();
			previousItem = postfix.read();
			postfix.pop();
			postfix.push(currentItem * previousItem);
		}

		if (expression[i] == '-') {
			currentItem = postfix.read();
			postfix.pop();
			previousItem = postfix.read();
			postfix.pop();
			postfix.push(currentItem - previousItem);
		}

		if (expression[i] == '/') {
			currentItem = postfix.read();
			postfix.pop();
			previousItem = postfix.read();
			postfix.pop();
			postfix.push(currentItem / previousItem);
		}

		cout << postfix;
	}

	cout << endl;
	cout << expression << " = " << postfix.read() << endl;
	cout << endl;
}

void convertToRPN(char* expression) {
	int expLength = strlen(expression);
	stack<char> infix;

	cout << "Converting " << expression << " from infix to postfix notation..." << endl;

	for (int i = 0; i < expLength; i++) {
		if (expression[i] == ')') {
			cout << infix.read() << " ";
			infix.pop();
		}

		if ((expression[i] == '+') || (expression[i] == '*') || expression[i] == '-' || expression[i] == '/')
			infix.push(expression[i]);

		if ((expression[i] >= '0') && (expression[i] <= '9'))
			cout << expression[i] << " ";	//	Write number to new expression
	}

	cout << endl;
}

bool isPalindrome(char* str) { 
	int strLength = strlen(str);
	stack<char> palindrome;

	for (int i = 0; i < strLength; i++)
		palindrome.push(str[i]);

	bool flag = true;
	for (int i = 0; i < strLength; i++) {
		if (palindrome.read() != str[i])
			return false;

		palindrome.pop();
	}

	return flag; 
}
