#ifndef LINK_H
#define LINK_H

#include "node.h"

//  L = link type, N = node type
template<class L, class N>
class link {
public:
    link();
    ~link();
    void setSrcNode(node<N>*);
    node<N>* getSrcNode() const;
    void setDestNode(node<N>*);
    node<N>* getDestNode() const;
    void setInfo(L);
    L getInfo() const;
private:
    node<N>* src;
    node<N>* dest;
    L info;
};

template<class L, class N>
link<L, N>::link() {
    src = nullptr;
    dest = nullptr;
}

template<class L, class N>
link<L, N>::~link() {
    delete src;
    delete dest;
}

template<class L, class N>
void link<L, N>::setSrcNode(node<N>* n) { src = n; }

template<class L, class N>
void link<L, N>::setDestNode(node<N>* n) { dest = n; }

template<class L, class N>
node<N>* link<L, N>::getSrcNode() const { return src; }

template<class L, class N>
node<N>* link<L, N>::getDestNode() const { return dest; }

template<class L, class N>
void link<L, N>::setInfo(L lnk) { info = lnk; }

template<class L, class N>
L link<L, N>::getInfo() const { return info; }

#endif // LINK_H