#ifndef UTIL_H
#define UTIL_H

#include "bintree.h"
#include "node.h"
#include "queue.h"

//	Populates the tree with some integers.
template<class T>
void acquireTree(bintree<T> &tree) {
	tree.insertRoot();
	node<T>* radix = tree.getRoot();
	tree.writeNode(radix,49);

	tree.insertLeftChild(radix);
	node<T>* left = tree.leftChild(radix);
	tree.writeNode(left,22);

	tree.insertRightChild(radix);
	node<T>* right = tree.rightChild(radix);
	tree.writeNode(right,82);

	tree.insertLeftChild(left);
	node<T>* leftA = tree.leftChild(left);
	tree.writeNode(leftA,17);

	tree.insertLeftChild(right);
	node<T>* leftB = tree.leftChild(right);
	tree.writeNode(leftB,57);

	tree.insertRightChild(right);
	node<T>* rightA = tree.rightChild(right);
	tree.writeNode(rightA,88);
}

template<class T>
void preVisit(node<T>* u, bintree<T>& tree) {
	if (!tree.isEmpty()) {
		std::cout << tree.readNode(u) << ' ';

		if (!tree.leftEmpty(u))
			preVisit(tree.leftChild(u), tree);

		if (!tree.rightEmpty(u))
			preVisit(tree.rightChild(u), tree);
	}
}

template<class T>
void postVisit(node<T>* u, bintree<T>& tree) {
	if (!tree.isEmpty()) {
		if (!tree.leftEmpty(u))
			postVisit(tree.leftChild(u), tree);

		if (!tree.rightEmpty(u))
			postVisit(tree.rightChild(u), tree);

		std::cout << tree.readNode(u) << ' ';
	}
}

template<class T>
void inVisit(node<T>* u, bintree<T>& tree) {
	if (!tree.isEmpty()) {
		if (!tree.leftEmpty(u)) inVisit(tree.leftChild(u), tree);
		if (!tree.rightEmpty(u)) inVisit(tree.rightChild(u), tree);
		std::cout << tree.readNode(u) << ' ';	//	Identical to postVisit
	}
}

template<class T>
void breadth(bintree<T>& tree) {
	queue<node<T>*> q;
	node<T>* n = new node<T>;

	if (!tree.isEmpty()) {
		std::cout << tree.readNode(tree.getRoot()) << ' ';
		q.enqueue(tree.getRoot());
		while (!q.isEmpty()) {
			n = q.read();
			q.dequeue();
			if (!tree.leftEmpty(n)) {
				std::cout << tree.readNode(tree.leftChild(n)) << ' ';
				q.enqueue(tree.leftChild(n));
			}

			if (!tree.rightEmpty(n)) {
				std::cout << tree.readNode(tree.rightChild(n)) << ' ';
				q.enqueue(tree.rightChild(n));				
			}
		}
	}
}

template<class T>
int compare(T a, T b) {
	if (a < b) return -1;
	if (a == b) return 0;
	if (a > b) return 1;
}

template<class T>
void insertOrdered(bintree<T>& tree, T x, node<T>* u) {
	if (tree.isEmpty()) {
		tree.insertRoot();
		tree.writeNode(tree.getRoot(), x);
	} else {
		if (compare(x, tree.readNode(u)) == -1) {
			if (tree.leftEmpty(u)) {
				tree.insertLeftChild(u);
				tree.writeNode(tree.leftChild(u), x);
			} else insertOrdered(tree, x, tree.leftChild(u));
		}

		if (compare(x, tree.readNode(u)) == 1) {
			if (tree.rightEmpty(u)) {
				tree.insertRightChild(u);
				tree.writeNode(tree.rightChild(u), x);
			} else insertOrdered(tree, x, tree.rightChild(u));
		}
	}
}

#endif // UTIL_H