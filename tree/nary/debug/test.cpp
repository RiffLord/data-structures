/**
 * @file    test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Testing the n-ary tree implementation
 * @version 0.1
 * @date    2022-10-06
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
    Node *r = new Node(666);
    cout << "t.insertRoot(" << r << ")" << endl;
    t.insertRoot(r);
    if (!t.isEmpty()) cout << "t.isEmpty() : false" << endl;
    cout << "Root of tree:\n" << t.getRoot() << " : " << t.read(t.getRoot()) << endl;
    t.write(42, t.getRoot());
    cout << "Root after t.write()\n" << t.getRoot() << " : " << t.read(t.getRoot()) << endl;
    if (t.isLeaf(t.getRoot())) cout << "t.isLeaf(" << t.getRoot() << ") : true" << endl;
    Node *n = new Node(666);
    Tree y;
    y.insertRoot(n);
    t.insertFirstSubtree(y, t.getRoot());
    n = t.firstChild(t.getRoot());
    if (t.isLastSibling(n)) cout << "t.isLastSibling(" << n << ") : true" << endl;
    t.removeSubtree(n);
    if (t.isLeaf(t.getRoot())) cout << "t.isLeaf(" << t.getRoot() << ") : true" << endl;
    t.removeSubtree(t.getRoot());
    if (t.isEmpty()) cout << "t.isEmpty() : true\nafter calling t.removeSubtree on root" << endl;
    return 0;
}
