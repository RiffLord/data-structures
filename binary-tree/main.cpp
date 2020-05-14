#include <iostream>
#include "bintree.h"
#include "node.h"
#include "util.h"

using namespace std;

int main() {
    bintree<int> myTree;
    cout << (myTree.isEmpty() ? "true" : "false") << endl;

    acquireTree(myTree);
    cout << (myTree.isEmpty() ? "true" : "false") << endl;

    node<int>* rootRef = myTree.getRoot();
    preVisit(rootRef, myTree);
    cout << endl;

    postVisit(rootRef, myTree);
    cout << endl;

    inVisit(rootRef, myTree);
    cout << endl;

    breadth(myTree);    
}