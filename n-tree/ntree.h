#ifndef NTREE_H
#define NTREE_H

#include <assert.h>
#include "node.h"

template<class T>
class nTree {
public:
    nTree();
    ~nTree();
    void init();
    bool isEmpty() const;
    bool isLeaf(node<T>*) const;
    bool isLastBrother(node<T>*) const;
    void insertRoot(T);
    void insertFirstChild(node<T>*, T);
    void insertNextBrother(node<T>*, T);
    void removeSubtree(node<T>*);
    void writeNode(node<T>*, T);
    T getNode(node<T>*) const;
    node<T>* getRoot() const;
    node<T>* getFather(node<T>*) const;
    node<T>* getFirstChild(node<T>*) const;
    node<T>* getNextBrother(node<T>*) const;
    void printNode(node<T>*);
private:
    node<T>* root;
};

template<class T>
nTree<T>::nTree() { init(); }

template<class T>
nTree<T>::~nTree() {
    while (!isEmpty())
        removeSubtree(root);

    delete root;
}

template<class T>
void nTree<T>::init() { root = nullptr; }

template<class T>
bool nTree<T>::isEmpty() const { return root == nullptr; }

template<class T>
bool nTree<T>::isLeaf(node<T>* n) const {
    assert(!isEmpty());
    return n->getFirstChild() == nullptr;
} 

template<class T>
bool nTree<T>::isLastBrother(node<T>* n) const {
    return n->getNextBrother() == nullptr;
}

template<class T>
void nTree<T>::insertRoot(T item) {
    root = new node<T>;
    writeNode(root, item);
}

template<class T>
void nTree<T>::insertFirstChild(node<T>* n, T item) {
    assert(!isEmpty() && isLeaf(n));
    node<T>* child = new node<T>;
    writeNode(child, item);
    n->setFirstChild(child);
    child->setFather(n);
}

template<class T>
void nTree<T>::insertNextBrother(node<T>* n, T item) {
    if ((!isEmpty() && isLastBrother(n) && n != root)) {
        node<T>* brother = new node<T>;
        writeNode(brother, item);
        n->setNextBrother(brother);
        brother->setFather(n->getFather());
    }
}

template<class T>
T nTree<T>::getNode(node<T>* n) const { return n->getData(); }

template<class T>
void nTree<T>::writeNode(node<T>* n, T item) { n->setData(item); }

template<class T>
node<T>* nTree<T>::getRoot() const { return root; }

template<class T>
node<T>* nTree<T>::getFather(node<T>* n) const {
    assert(!isEmpty() && n != root);
    return n->getFather();
}

template<class T>
node<T>* nTree<T>::getFirstChild(node<T>* n) const {
    assert(!isEmpty() && !isLeaf(n));
    return n->getFirstChild();
}

template<class T>
node<T>* nTree<T>::getNextBrother(node<T>* n) const {
   // if (!isEmpty() && !isLastBrother(n))
    return n->getNextBrother();
}

template<class T>
void nTree<T>::removeSubtree(node<T>* n) {
    node<T>* temp;

	if (n != root) {
        if ((n->getFather())->getFirstChild() ==  n)
        	(n->getFather())->setFirstChild(n->getNextBrother());
		else {
            temp = (n->getFather())->getFirstChild();
            while (temp->getNextBrother() != n)
            	temp = temp->getNextBrother();
            temp->setNextBrother(n->getNextBrother());
		}
    } else {
    	node<T>* u;
    	u = getFirstChild(root);
    	while(!isLastBrother(u)) {
    		removeSubtree(u);
    		u = getNextBrother(u);
    	}
    	root = nullptr;
    }

    if (n->getFirstChild() != nullptr) {
        temp = n->getFirstChild();
        if (temp->getNextBrother() != NULL)
        	removeSubtree(temp->getNextBrother());
        removeSubtree(temp);
    }

    delete n;
}

template<class T>
void nTree<T>::printNode(node<T>* n) {
    if (n != nullptr) std::cout << getNode(n) << ' ';
}

#endif // !NTREE_H