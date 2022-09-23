/**
 * @file    test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Test file for the binary tree data structure
 * @version 0.3
 * @date    2022-08-30
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef __linux__
    #include "../tree.h"
#elif _WIN32
    #include "..\tree.h"
#else
    #error Platform not supported
#endif

int main(void) {
    using namespace std;
    srand(time(NULL));
    Tree t;
    if (t.isEmpty()) cout << "t.isEmpty() : true" << endl;
    Node *n = new Node(666);
    t.setRoot(n);
    delete n;
    cout << t.getRoot()->getData() << '\n' << t.getRoot()->getParent() << '\n' <<
            t.getRoot()->getSibling() << '\n' << t.getRoot()->getLeftChild() << '\n' <<
            t.getRoot()->getRightChild() << endl;
    if (!t.isEmpty()) cout << "t.isEmpty() : false" << endl;
    cout << t.getRoot() << endl;
    return 0;
}
