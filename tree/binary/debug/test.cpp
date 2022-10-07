/**
 * @file    test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Test file for the binary Tree<int> data structure
 * @version 0.9
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
    Tree<int> t;
    if (t.isEmpty()) cout << "t.isEmpty() : true" << endl;
    Node<int> *n = new Node<int>(666);
    cout << "Created new Node<int> n @ memory location " << n << endl;
    t.insertRoot(n);
    if (t.hasLeftChild(t.getRoot())) cout << "t.hasLeftChild(t.getRoot()) : true\n";
    else cout << "t.hasLeftChild(t.getRoot()) : false\n";
    if (t.hasRightChild(t.getRoot())) cout << "t.hasRightChild(t.getRoot()) : true\n";
    else cout << "t.hasRightChild(t.getRoot()) : false\n";
    cout << "t.getRoot() : " << t.getRoot() << " : " << t.read(t.getRoot()) << endl;
    n = t.getRoot();
    t.insertLeftChild(rand() % 99, n);
    t.insertRightChild(rand() % 99, n);
    n = t.leftChild(n);
    t.insertLeftChild(rand() % 99, n);
    t.insertRightChild(rand() % 99, n);
    n = t.rightChild(t.getRoot());
    t.insertLeftChild(rand() % 99, n);
    t.insertRightChild(rand() % 99, n);    
    t.print(t.getRoot());
    cout << endl << "n : " << n << "\tt.read(n) : " << t.read(n) << endl;
    t.write(42, n);
    cout << "n : " << n << "\tt.read(n) : " << t.read(n) << endl;
    n = t.getRoot();
    if (!t.isEmpty()) cout << "t.isEmpty() : false" << endl;
    cout << "t.removeSubtree(" << n << ")..." << endl;
    t.removeSubtree(n);
    if (t.isEmpty()) cout << "t.isEmpty() : true" << endl;
    //  Will cause std::runtime_error
    //t.print(t.getRoot());
    return 0;
}
