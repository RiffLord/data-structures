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
    printLinks(g);
    cout << "Vertices: " << vertices(g) << endl;
    cout << "Lines:    " << lines(g) << endl;

    node<nd>* position = g.nodes.read(g.nodes.first());
    cout << "DFS:" << endl;
    dfs(g, position);

    //  TODO: verify distance function works correctly.
}