#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "link.h"
#include "linked_list.h"

template<class L, class N>
class graph {
public:
    linked_list<link<L, N>*> links;
    linked_list<node<N>*> nodes;

    graph();
    ~graph();
    void init();
    bool isEmpty() const;
    bool nodeExists(node<N>*) const;
    bool linkExists(node<N>*, node<N>*) const;
    void insertNode(node<N>*, N);
    void insertLink(node<N>*, node<N>*, link<L, N>*, L);
    void removeNode(node<N>*);
    void removeLink(node<N>*, node<N>*);
    linked_list<node<N>*> adjecent(node<N>*) const;

    listNode<link<L, N>*>* linkPosition(node<N>*, node<N>*) const;
    listNode<node<N>*>* nodePosition(node<N>*) const;
};

template<class L, class N>
graph<L, N>::graph() { init(); }

template<class L, class N>
graph<L, N>::~graph() {}

template<class L, class N>
void graph<L, N>::init() {
    links.init();
    nodes.init();
}

template<class L, class N>
bool graph<L, N>::isEmpty() const {
    if (nodes.isEmpty()) return true;
    return false;
}

template<class L, class N>
bool graph<L, N>::nodeExists(node<N>* n) const {
    if (!nodes.isEmpty()) {
        listNode<node<N>*>* position = nodes.first();
        while (!nodes.end(position)) {
            if (position->getData() == n) return true;
            else
                position = nodes.next(position);
        }
    }
    return false;
}

template<class L, class N>
bool graph<L, N>::linkExists(node<N>* n, node<N>* m) const {
    if (!links.isEmpty()) {
        if (nodeExists(n) && nodeExists(m)) {
            listNode<link<L, N>*>* position = links.first();
            while (!links.end(position)) {
                link<L, N>* l = position->getData();
                if (l->getSrcNode() == n && l->getDestNode() == m)
                    return true;
                else
                    position = links.next(position);
            }
        }
    }
    return false;
}

template<class L, class N>
void graph<L, N>::insertLink(node<N>* n, node<N>* m, link<L, N>* l, L value) {
    if (nodeExists(n) && nodeExists(m)) {
        if (!linkExists(n, m)) {
            l->setInfo(value);
            l->setSrcNode(n);
            l->setDestNode(m);
            listNode<link<L, N>*>* position = links.first();
            links.insert(l, position);
        } else std::cout << "Link already established between nodes " << n << " & " << m << std::endl;
    } else std::cout << "Error. Attempting to create link including non-existant nodes." << std::endl;
}

template<class L, class N>
void graph<L, N>::insertNode(node<N>* n, N item) {
    listNode<node<N>*>* position = nodes.first();
    n->setInfo(item);
    nodes.insert(n, position);
}

template<class L, class N>
void graph<L, N>::removeNode(node<N>* n) {
    if (!nodes.isEmpty()) {
        if (nodeExists(n)) {
            listNode<link<L, N>*>* linkPos = links.first();
            node<N>* src;
            node<N>* dest;
            while (!links.end(linkPos)) {
                src = links.read(linkPos)->getSrcNode();
                dest = links.read(linkPos)->getDestNode();
                if (n->getInfo() == src->getInfo() || n->getInfo() == dest->getInfo()) {
                    links.remove(linkPos);
                    linkPos = links.first();
                }
                linkPos = links.next(linkPos);
            }

            listNode<node<N>*>* nodePos = nodes.first();
            node<N>* nd;
            while (!nodes.end(nodePos) && nodeExists(n)) {
                nd = nodes.read(nodePos);
                if (n->getInfo() == nd->getInfo())
                    nodes.remove(nodePos);

                nodePos = nodes.next(nodePos);
            }
        } else std::cout << "Node doesn't exist." << std::endl;
    } else std::cout << "No nodes to remove." << std::endl;
}

template<class L, class N>
listNode<link<L, N>*>* graph<L, N>::linkPosition(node<N>* n, node<N>* m) const {
    listNode<link<L, N>*>* position;
    link<L, N>* l;
    if (!links.isEmpty()) {
        if (nodeExists(n) && nodeExists(m)) {
            position = links.first();
            while (!links.end(position)) {
                l = position->getData();
                if (l->getSrcNode() == n && l->getDestNode() == m)
                    return position;
                else
                    position = links.next(position);
            }
        }
    } else std::cout << "The specified nodes don't exist." << std::endl;
    return nullptr;
}

template<class L, class N>
listNode<node<N>*>* graph<L, N>::nodePosition(node<N>* n) const {
    listNode<node<N>*>* position;
    if (!nodes.isEmpty()) {
        position = nodes.first();
        while (!nodes.end(position)) {
            if (position->getData() == n) return position;
            else
                position = nodes.next(position);
        }
    }
    return nullptr;
}

template<class L, class N>
void graph<L, N>::removeLink(node<N>* n, node<N>* m) {
    if (!links.isEmpty()) {
        if (linkExists(n, m)) {
            listNode<link<L, N>*>* position = linkPosition(n, m);
            links.remove(position);
        } else std::cout << "Link between nodes " << n << " & " << m << " doesn't exist." << std::endl;
    } else std::cout << "No links in this graph." << std::endl;
}

template<class L, class N>
linked_list<node<N>*> graph<L, N>::adjecent(node<N>* n) const {
    linked_list<node<N>*> temp;
    temp.init();
    if (!nodes.isEmpty()) {
        if (nodeExists(n)) {
            listNode<link<L, N>*>* position = links.first();
            node<N>* src;
            node<N>* dest;
            while (!links.end(position)) {
                src = links.read(position)->getSrcNode();
                dest = links.read(position)->getDestNode();
                if (n->getInfo() == src->getInfo()) {
                    temp.insert(dest, temp.first());
                }
                position = links.next(position);
            }
        } else std::cout << "The node doesn't exist." << std::endl;
    } else std::cout << "The graph doesn't contain nodes." << std::endl;
    return temp;
}

#endif // GRAPH_H