/**
 * @file      heapsort.h
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Heapsort algorithm definition file
 * @version   0.1
 * @date      2022-10-20
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "queue.h"

//  Sorts the sub-array a[l],...,a[r] of a using a priority queue
template <class T> void heapsort(T a[], int l, int r) {
    int k;
    Queue<T> q(r - l + 1);
    for (k = l; k <= r; k++) q.insert(a[k]);
    for (k = r; k >= l; k--) {
        a[k] = q.min();
        q.removeMin();
    }
}
