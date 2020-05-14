#include <iostream>
#include "ntree.h"
#include "util.h"

using namespace std;

int main() {
    nTree<int> myTree;
    cout << "myTree.isEmpty(): " << (myTree.isEmpty() ? "true" : "false") << endl;
    cout << "Populating tree... ";
    acquireTree(myTree);
    cout << "myTree.isEmpty(): " << (myTree.isEmpty() ? "true" : "false") << endl;
    int nNodes = 0;
    cout << "Number of nodes: " << countNodes(myTree, myTree.getRoot(), nNodes) << endl;
    int nLeaves = 0;
    cout << "Number of leaves: " << countLeaves(myTree, myTree.getRoot(), nLeaves) << endl;
    cout << "Searching for 5 in tree: " << search(myTree, 5) << endl;
    cout << "Searching for 4 in tree: " << search(myTree, 4) << endl;
    cout << "Searching for 666 in tree: " << search(myTree, 666) << endl;
    cout << "Finished.\n";
    preVisit(myTree, myTree.getRoot());
    cout << endl;
    nTree<char> cTree;
    preVisit(cTree, cTree.getRoot());
    postVisit(myTree, myTree.getRoot());
    cout << endl;
    postVisit(cTree, cTree.getRoot());
    symmetricVisit(myTree, myTree.getRoot());
    cout << endl;
    symmetricVisit(cTree, cTree.getRoot());    
    breadth(myTree, myTree.getRoot());
    cout << endl;
    breadth(cTree, cTree.getRoot());

    cout << "Removing first child subtree from myTree..." << endl;
    myTree.removeSubtree(myTree.getFirstChild(myTree.getRoot()));
    preVisit(myTree, myTree.getRoot());
}