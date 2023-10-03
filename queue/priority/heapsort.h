/**
 * @file      heapsort.h
 * @author    Bruno Pezer
 * @brief     Heapsort algorithm definition file
 * @version   0.2
 * @date      2022-10-20
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#include "queue.h"

/**
 * @brief    Sorts the sub-array a[l],...,a[r] of a using a priority queue.
 *
 * @tparam T Queue type
 * @param a  Sub-array to sort
 * @param l  Sub-array left bound
 * @param r  Sub-array right bound
 */
template <class T> void heapsort(T a[], int l, int r) {
    int k;                 // Array position counter
    Queue<T> q(r - l + 1); // Creates a new array of size r - l + 1.
    // Populates the queue with the contents of the sub-array.
    for (k = l; k <= r; k++) q.insert(a[k]);
    for (k = r; k >= l; k--) {
        a[k] = q.min();
        q.removeMin();
    }
}
