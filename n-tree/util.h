#ifndef UTIL_H
#define UTIL_H

#include "ntree.h"
#include "node.h"
#include "queue.h"

//	Populates the tree with some integers.
template<class T>
void acquireTree(nTree<T>& tree) {
    node<T>* u = new node<T>;

	tree.insertRoot(5);

	u = tree.getRoot();
	tree.insertFirstChild(u, 4);

	u = tree.getFirstChild(u);
	tree.insertNextBrother(u, 15);

	u = tree.getNextBrother(u);
	tree.insertNextBrother(u, 6);

	u = tree.getNextBrother(u);
	tree.insertFirstChild(u, 21);

	u = tree.getFirstChild(u);
	tree.insertNextBrother(u, 20);

	u = tree.getFirstChild(tree.getRoot());
	tree.insertFirstChild(u, 8);

	u = tree.getFirstChild(u);
	tree.insertNextBrother(u, 9);

	u = tree.getNextBrother(u);
	tree.insertFirstChild(u, 12);

	u = tree.getFirstChild(u);
	tree.insertNextBrother(u, 11);

	u = tree.getNextBrother(u);
	tree.insertNextBrother(u, 3);
}

template<class T>
int compare(T a, T b) {
	if (a < b) return -1;
	if (a == b) return 0;
	if (a > b) return 1;
}

template<class T>
int countNodes(nTree<T>& tree, node<T>* n, int i) {
	node<T>* m;
	if (!tree.isEmpty()) {
		i++;
		if (!tree.isLeaf(n)) {
			m = tree.getFirstChild(n);
			while (!tree.isLastBrother(m)) {
				i = countNodes(tree, m, i);
				m = tree.getNextBrother(m);
			}
			i = countNodes(tree, m, i);
		}
	}
	return i;
}

template<class T>
int countLeaves(nTree<T>& tree, node<T>* n, int i) {
	node<T>* m;
	if (!tree.isEmpty() && n != nullptr) {
		if (tree.isLeaf(n)) i++;
		else {
			m = tree.getFirstChild(n);
			while (!tree.isLastBrother(m)) {
				i = countLeaves(tree, m, i);
				m = tree.getNextBrother(m);
			}
			i = countLeaves(tree, m, i);
		}
	}
	return i;
}

//	Searches for the specified item within the tree and returns
//  it if found or returns a nullptr if not found.
template<class T>
node<T>* search(nTree<T>& tree, T item) {
	node<T>* root = tree.getRoot();
	if (root->getData() == item) return root;

	node<T>* temp = new node<T>;
	T t;
	bool found = false;
	queue<node<T>*> nodeQ;
	nodeQ.enqueue(root);
	while (!nodeQ.isEmpty() && !found) {
		temp = nodeQ.read();
		t = temp->getData();
		nodeQ.dequeue();
		if (t == item) {
			found = true;
			return temp;
		} else if (!tree.isLeaf(temp)) {
			temp = tree.getFirstChild(temp);
			while (!tree.isLastBrother(temp)) {
				nodeQ.enqueue(temp);
				temp = tree.getNextBrother(temp);
			}
			nodeQ.enqueue(temp);
		}
	}

	if (nodeQ.isEmpty()) std::cout << "Item not found..." << std::endl;
	return nullptr;
}

//	Visits
template<class T>
void preVisit(nTree<T>& tree, node<T>* n) {
	node<T>* m;
	if (!tree.isEmpty()) {
		tree.printNode(n);
		if (!tree.isLeaf(n)) {
			m = tree.getFirstChild(n);
			while (!tree.isLastBrother(m)) {
				preVisit(tree, m);
				m = tree.getNextBrother(m);
			}
			preVisit(tree, m);
		}
	} else std::cout << "Empty tree." << std::endl;
}

template<class T>
void postVisit(nTree<T>& tree, node<T>* n) {
	node<T>* m;
	if (!tree.isEmpty()) {
		if (!tree.isLeaf(n)) {
			m = tree.getFirstChild(n);
			while (!tree.isLastBrother(m)) {
				postVisit(tree, m);
				m = tree.getNextBrother(m);
			}
			postVisit(tree, m);
		}
		tree.printNode(n);
	} else std::cout << "Empty tree." << std::endl;
}

template<class T>
void symmetricVisit(nTree<T>& tree, node<T>* n) {
	node<T>* m;
	if (!tree.isEmpty()) {
		if (tree.isLeaf(n)) tree.printNode(n);
		else {
			m = tree.getFirstChild(n);
			symmetricVisit(tree, m);
			tree.printNode(n);
			while (!tree.isLastBrother(m)) {
				m = tree.getNextBrother(m);
				symmetricVisit(tree, m);
			}
		}
	} else std::cout << "Empty tree." << std::endl;
}

template<class T>
void breadth(nTree<T>& tree, node<T>* n) {
	node<T>* temp;
	if (!tree.isEmpty()) {
		queue<node<T>*> nodeQ;
		nodeQ.enqueue(n);
		while (!nodeQ.isEmpty()) {
			temp = nodeQ.read();
			tree.printNode(temp);
			nodeQ.dequeue();
			if (!tree.isLeaf(temp)) {
				temp = tree.getFirstChild(temp);
				while (!tree.isLastBrother(temp)) {
					nodeQ.enqueue(temp);
					temp = tree.getNextBrother(temp);
				}
				nodeQ.enqueue(temp);
			}
		}
	} else std::cout << "Empty tree." << std::endl;
}

#endif // UTIL_H