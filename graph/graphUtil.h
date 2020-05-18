#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H

#include "graph.h"
#include "node.h"
#include "link.h"
#include "linked_list.h"
#include "queue.h"

template<class L, class N>
void acquire(graph<L, N>& g) {
    node<N>* a = new node<N>;
    node<N>* b = new node<N>;
    node<N>* c = new node<N>;
    node<N>* d = new node<N>;
    node<N>* e = new node<N>;
    node<N>* f = new node<N>;
    link<L, N>* line1 = new link<L, N>;
    link<L, N>* line2 = new link<L, N>;
    link<L, N>* line3 = new link<L, N>;
    link<L, N>* line4 = new link<L, N>;
    link<L, N>* line5 = new link<L, N>;
    link<L, N>* line6 = new link<L, N>;
    link<L, N>* line7 = new link<L, N>;
    link<L, N>* line8 = new link<L, N>;
    link<L, N>* line9 = new link<L, N>;

    g.insertNode(a, "A");
    g.insertNode(b, "B");
    g.insertNode(c, "C");
    g.insertNode(d, "D");
    g.insertNode(e, "E");
    g.insertNode(f, "F");

    g.insertLink(a, b, line1, "(A, B)");
    g.insertLink(a, d, line2, "(A, D)");
    g.insertLink(b, c, line3, "(B, C)");
    g.insertLink(c, a, line4, "(C, A)");
    g.insertLink(d, c, line5, "(D, C)");
    g.insertLink(c, f, line6, "(C, F)");
    g.insertLink(c, e, line7, "(C, E)");
    g.insertLink(f, e, line8, "(F, E)");
    g.insertLink(e, d, line9, "(E, D)");
}

template<class L, class N>
void printNodes(graph<L, N>& g) {
    node<N>* position;
    listNode<node<N>*>* pos = g.nodes.first();
    listNode<node<N>*>* adjPos;
    linked_list<node<N>*> adjNodes;
    while (pos->getData() != nullptr) {
        adjNodes.init();
        position = pos->getData();
        adjNodes = g.adjecent(position);
        std::cout << std::endl;
        std::cout << "Node# " << pos->getData()->getInfo() << ' ';
        adjPos = adjNodes.first();
        while (adjPos->getData() != nullptr) {
            std::cout << "Adjecent: " << adjPos->getData()->getInfo() << ' ';
            adjPos = adjNodes.next(adjPos);
        }
        std::cout << " " << std::endl;
        pos = g.nodes.next(pos);
    }
    std::cout << std::endl;
}

template<class L, class N>
void printLinks(graph<L, N>& g) {
    listNode<link<L, N>*>* pos = g.links.first();
    while (pos->getData() != nullptr) {
        std::cout << "Link#" << pos->getData()->getInfo() << ' '
                  << pos->getData()->getSrcNode()->getInfo() << "->"
                  << pos->getData()->getDestNode()->getInfo() << std::endl;
        pos = g.links.next(pos);
    }
    std::cout << std::endl;
}

template<class L, class N>
void readNode(graph<L, N>& g, node<N>* n) {
    if (!n->isEmpty()) std::cout << n->getInfo() << ' ';
}

template<class L, class N>
int vertices(graph<L, N>& g) {
    int i = 0;
    listNode<node<N>*>* pos = g.nodes.first();
    while (!g.nodes.end(pos)) {
        pos = g.nodes.next(pos);
        i++;
    } 
    return i; 
}

template<class L, class N>
int lines(graph<L, N>& g) {
    int i = 0;
    listNode<link<L, N>*>* pos = g.links.first();
    while (!g.links.end(pos)) {
        pos = g.links.next(pos);
        i++;
    } 
    return i; 
}

template<class L, class N>
void unvisitVertices(graph<L, N> &g) {
    node<N>* n;
    listNode<node<N>*>* pos;
    if (!g.nodes.isEmpty()) {
        pos = g.nodes.first();
        while (!g.nodes.end(pos)) {
            n = g.nodes.read(pos);
            n->visitState(false);
            pos = g.nodes.next(pos);
        }
    }
}

template<class L, class N>
void dfs(graph<L, N>& g, node<N>* n) {
    unvisitVertices(g);
    readNode(g, n);
    listNode<node<N>*>* pos;
    node<N>* adj;
    pos = g.adjecent(n).first();
    while (!g.adjecent(n).end(pos)) {
        adj = g.adjecent(n).read(pos);
        if (adj->visit()) dfs(g, adj);
        pos = g.adjecent(n).next(pos);
    }
}

#endif // GRAPHUTIL_H