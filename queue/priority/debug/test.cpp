/**
 * @file      test.cpp
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Testing the priority queue implementation
 * @version   0.2
 * @date      2022-10-16
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#ifdef __linux__
    #include "../queue.h"
    #include "../heapsort.h"
#elif _WIN32
    #include "..\queue.h"
    #include "..\heapsort.h"
#else
    #error Platform not supported
#endif

int main(void) {
    using namespace std;
    Queue<char> q;
    q.insert('a');
    q.insert('q');
    q.insert('+');
    q.insert('l');
    q.insert('*');
    cout << q.min() << endl;
    q.removeMin();
    cout << q.min() << endl;
    cout << "Testing heapsort function on an array..." << endl;
    int symbols[10] = {1, 2, 3, 8, 5, 9, 7, 10, 4, 0};
    for (int i = 0; i < 10; i++) {
        cout << symbols[i] << ' ';
        if (i % 5 == 0) cout << endl;
    }
    cout << endl;
    heapsort(symbols, 3, 7);
    for (int i = 0; i < 10; i++) {
        cout << symbols[i] << ' ';
        if (i % 5 == 0) cout << endl;
    }
    cout << endl;
    return 0;
}
