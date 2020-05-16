#include <string>
#include "graph.h"
#include "graphUtil.h"
#include "node.h"

using namespace std;

typedef string lnk;
typedef string nd;

int main() {
    graph<lnk, nd> g;
    node<nd>* n;
    node<nd>* m;
    g.removeNode(n);
    cout << "g.isEmpty(): " << (g.isEmpty() ? "true" : "false") << endl;
    g.removeLink(n, m);
    g.adjecent(n);
    acquire(g);
    cout << "g.isEmpty(): " << (g.isEmpty() ? "true" : "false") << endl;
    printNodes(g);
}