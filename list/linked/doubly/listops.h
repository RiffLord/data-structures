/**
 * @file    listops.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Funcions using the doubly linked array-based list class.
 * @version 0.1
 * @date    2022-08-16
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "list.h"

void firstN(unsigned int n, List::position p, List::position q, List &L, List &M) {
    if (n > 0) {
        L.insert(n, p);
        M.insert(n, q);
        q = M.next(q);
        firstN(n - 1, p, q, L, M);
    }
}
