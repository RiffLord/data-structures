/**
 * @file nodetest.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Testing node class for use in a binary tree data structure
 * @version 0.2
 * @date 2022-09-05
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
    Node *n = new Node(666);
    using namespace std;
    cout << "Printing Node data..." << endl
         << "Data:        " << n->getData() << endl
         << "Parent:      " << n->getParent() << endl
         << "Sibling:     " << n->getSibling() << endl
         << "Left Child:  " << n->getLeftChild() << endl
         << "Right Child: " << n->getRightChild() << endl;

    Node *m = new Node(42, n);
    Node *o = new Node(13, n, m);
    n->setLeftChild(m);
    n->setRightChild(o);
    m->setSibling(o);

    cout << "Printing Node data..." << endl
         << "Data:        " << n->getData() << endl
         << "Parent:      " << n->getParent() << endl
         << "Sibling:     " << n->getSibling() << endl
         << "Left Child:  " << n->getLeftChild() << endl
         << "Right Child: " << n->getRightChild() << endl;

    cout << "Printing Node data..." << endl
         << "Data:        " << m->getData() << endl
         << "Parent:      " << m->getParent() << endl
         << "Sibling:     " << m->getSibling() << endl
         << "Left Child:  " << m->getLeftChild() << endl
         << "Right Child: " << m->getRightChild() << endl;

    cout << "Printing Node data..." << endl
         << "Data:        " << o->getData() << endl
         << "Parent:      " << o->getParent() << endl
         << "Sibling:     " << o->getSibling() << endl
         << "Left Child:  " << o->getLeftChild() << endl
         << "Right Child: " << o->getRightChild() << endl;

    Node *root = n;
    cout << "Printing binary tree..." << endl;
    cout << "   " << root->getData() << endl << "   / \\"
         << endl << "  " <<  root->getLeftChild()->getData() 
         << " " << root->getRightChild()->getData() << endl;
    return 0;
}