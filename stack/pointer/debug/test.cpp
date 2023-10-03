/**
 * @file    test.cpp
 * @author  Bruno Pezer
 * @brief   Testing and debugging a generic pointer-based stack's operations
 * @version 0.4
 * @date    2022-08-22
 *
 * @copyright NO COPYRIGHT !(c) 2022
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef __linux__
    #include "../stack.h"
#elif _WIN32
    #include "..\stack.h"
#else
    #error Platform not supported
#endif

int main(void) {
    using namespace std;
    srand(time(NULL));
    Stack<float> myStack;
    if (myStack.isEmpty()) cout << "myStack.isEmpty() : true" << endl;
    cout << "myStack.getSize() : " << myStack.getSize() << endl;
    int i;
    for (i = 0; i < 10; i++) {
        myStack.push(i + rand() % 89);
    }
    if (!myStack.isEmpty()) cout << "myStack.isEmpty() : false" << endl;
    cout << "myStack.getSize() : " << myStack.getSize() << endl;
    cout << "myStack.read() : " << myStack.read() << endl;
    cout << "Printing myStack:" << endl << myStack << endl;
    cout << "Pushing " << 666 << " into myStack" << endl;
    myStack.push(666);
    cout << myStack;
    cout << "myStack.getSize() : " << myStack.getSize() << endl;
    cout << "Popping from myStack" << endl;
    myStack.pop();
    cout << myStack;
    cout << "myStack.getSize() : " << myStack.getSize() << endl;
    Stack<float> otherStack = myStack;
    cout << "Printing otherStack after initializing with overloaded copy constructor" << endl;
    cout << otherStack << endl << "otherStack.getSize() : " << otherStack.getSize() << endl;
    if (otherStack == myStack) cout << "otherStack == myStack : true" << endl;
    myStack.pop();
    if (otherStack != myStack) cout << "otherStack != myStack : true" << endl;
    myStack.push(otherStack.read());
    if (otherStack == myStack) cout << "otherStack == myStack : true" << endl;
    myStack.pop();
    myStack.push(666);
    if (otherStack != myStack) cout << "otherStack != myStack : true" << endl;
    return 0;
}
