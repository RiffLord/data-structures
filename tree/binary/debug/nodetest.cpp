/**
 * @file      nodetest.cpp
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Testing a generic node class for use in a binary tree data structure
 * @version   0.3
 * @date      2022-09-05
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#ifdef __linux__
     #include "../node.h"
#elif _WIN32
     #include "..\node.h"
#else
     #error Platform not supported
#endif

int main(void) {
    Node<int> *n = new Node<int>(666);
    using namespace std;
    cout << "Printing node data..." << endl
         << "Data:        " << n->getData() << endl
         << "Parent:      " << n->getParent() << endl
         << "Left Child:  " << n->getLeftChild() << endl
         << "Right Child: " << n->getRightChild() << endl;

    Node<int> *m = new Node<int>(42, n);
    Node<int> *o = new Node<int>(13, n, m);
    n->setLeftChild(m);
    n->setRightChild(o);

    cout << "Printing Node<int> data..." << endl
         << "Data:        " << n->getData() << endl
         << "Parent:      " << n->getParent() << endl
         << "Left Child:  " << n->getLeftChild() << endl
         << "Right Child: " << n->getRightChild() << endl;

    cout << "Printing Node<int> data..." << endl
         << "Data:        " << m->getData() << endl
         << "Parent:      " << m->getParent() << endl
         << "Left Child:  " << m->getLeftChild() << endl
         << "Right Child: " << m->getRightChild() << endl;

    cout << "Printing Node<int> data..." << endl
         << "Data:        " << o->getData() << endl
         << "Parent:      " << o->getParent() << endl
         << "Left Child:  " << o->getLeftChild() << endl
         << "Right Child: " << o->getRightChild() << endl;

    Node<int> *root = n;
    cout << "Printing binary tree..." << endl;
    cout << "   " << root->getData() << endl << "   / \\"
         << endl << "  " <<  root->getLeftChild()->getData() 
         << " " << root->getRightChild()->getData() << endl;
    return 0;
}