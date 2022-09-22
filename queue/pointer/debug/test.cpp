/**
 * @file    test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Testing/debugging a pointer-based queue data structure
 * @version 0.2
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "..\queue.h"

int main(void) {
    using namespace std;
    srand(time(NULL));
    Queue q;
    if (q.isEmpty()) cout << "q.isEmpty() : true" << endl;
    cout << "q.getSize() : " << q.getSize() << endl;
    q.push(rand() % 99);
    if (!q.isEmpty()) cout << "q.isEmpty() : false" << endl;
    int i;
    for (i = 0; i < 10; i++) q.push(i + rand() % 89);
    cout << q << "q.getSize() : " << q.getSize() << endl;
    q.pop();
    cout << q << "q.getSize() : " << q.getSize() << endl;
    while (!q.isEmpty()) {
        q.pop();
    }
    cout << q << "q.getSize() : " << q.getSize() << endl;
    /*Queue qq = q;
    if (q != qq) cout << "q != qq : true" << endl;
    if (q == qq) cout << "q == qq : true" << endl;
    cout << qq << endl;
    cout << "qq.getSize() : " << qq.getSize() << endl;*/
    return 0;
}
