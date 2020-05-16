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
    //  TODO: make this work...
    
    node<N>* position;
    listNode<node<N>*>* pos = g.nodes.first();
    listNode<node<N>*>* adjPos;
    linked_list<node<N>*> adjNodes;
    while (pos != NULL) {
        adjNodes.init();
        position = pos->getData();
        adjNodes = g.adjecent(position);
        std::cout << std::endl;
        std::cout << "Node# " << pos->getData()->getInfo() << ' ';
        adjPos = adjNodes.first();
        while (adjPos != NULL) {
            std::cout << "Adjecent: " << adjPos->getData()->getInfo() << ' ';
            adjPos = adjNodes.next(adjPos);

            std::cout << "Got here...1\n";
        }
        std::cout << "Got here...2\n";
        std::cout << " " << std::endl;
        pos = g.nodes.next(pos);
        std::cout << "Got here...3\n";
    }
    std::cout << std::endl;
}

template<class L, class N>
void printLinks(graph<L, N>& g) {}

template<class L, class N>
int vertices(graph<L, N>& g) { return 0; }

template<class L, class N>
int lines(graph<L, N>& g) { return 0; }

#endif // GRAPHUTIL_H