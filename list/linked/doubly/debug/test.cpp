/**
 * @file test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Testing the doubly linked array-based list
 * @version 0.4
 * @date    2022-08-16
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#ifdef __linux__
    #include "../list.h"
    #include "../listops.h"
#elif _WIN32
    #include "..\list.h"
    #include "..\listops.h"
#else
    #error Platform not supported
#endif

int main(void) {
    srand(time(NULL));
    List myList;
    List bigList(25);
    using namespace std;
    cout << "myList.getCapacity() : " << myList.getCapacity() << endl;
    cout << "bigList.getCapacity() : " << bigList.getCapacity() << endl;
    cout << "myList.getLength() : " << myList.getLength() << endl;
    cout << "bigList.getLength() : " << bigList.getLength() << endl;
    if (myList.isEmpty()) cout << "myList.isEmpty() : true" << endl;
    List::position p = myList.first();
    if (!myList.isValid(p)) cout << "myList.isValid(" << p << ") : false" << endl;
    myList.insert(42, p);
    if (!myList.isEmpty()) cout << "myList.isEmpty() : false" << endl;
    cout << "myList.getLength() : " << myList.getLength() << endl;
    if (myList.isValid(p)) cout << "myList.isValid(" << p << ") : true" << endl;
    cout << myList << endl;
    if (myList.endOfList(myList.next(p))) cout << "myList.endOfList(myList.next(" << p << ")) : true" << endl;
    myList.remove(p);
    cout << "myList after myList.remove(myList.first())...\n" << myList << endl;
    int i;
    for (i = 0; i < myList.getCapacity(); i++) {
        myList.insert(rand() % 99, p);
        p = myList.next(p);
    }
    cout << "myList after populating with data...\n" << myList << endl;
    cout << "myList.last() : " << myList.last() << endl;
    if (!myList.endOfList(myList.first())) cout << "myList.endOfList(myList.first()) : false" << endl;
    if (myList.endOfList(myList.next(myList.last()))) cout << "myList.endOfList(myList.next(myList.last())) : true" << endl;
    cout << myList.read(myList.first()) << endl << myList.read(myList.last()) << endl;
    cout << myList.read(myList.previous(myList.last())) << endl;
    if (!myList.isValid(myList.last() + 12)) cout << "myList.isValid(" << myList.last() + 12 << ") : false" << endl;
    if (myList.isValid(p)) cout << "myList.isValid(" << p << ") : true" << endl;
    myList.write(666, myList.last());
    cout << myList.read(myList.last()) << endl;
    myList.setCapacity(20);
    cout << "myList.getCapacity() : " << myList.getCapacity() << endl << myList << endl;
    if (!(myList == bigList)) cout << "myList == bigList : false" << endl;
    if ((myList != bigList)) cout << "myList != bigList : true" << endl;
    bigList = myList;
    cout << "Assigning myList to bigList...\n";
    if (myList == bigList) cout << "myList == bigList : true" << endl;
    if (!(myList != bigList)) cout << "myList != bigList : false" << endl;
    cout << "myList.getCapacity() : " << myList.getCapacity() << endl;
    p = myList.first();
    for (i = 0; i < myList.getCapacity(); i++) {
        if (myList.endOfList(p)) {
            if (i % 2 == 0) myList.insert(42, p);
            else if (i % 3 == 0) myList.insert(666, p);
            else if (i % 5 == 0) myList.insert(13, p);
            else myList.insert(rand() % 99, p);            
        } else {        
            if (i % 2 == 0) myList.write(42, p);
            else if (i % 3 == 0) myList.write(666, p);
            else if (i % 5 == 0) myList.write(13, p);
            else myList.write(rand() % 99, p);
        }
        p = myList.next(p);
    }
    cout << myList << endl;
    cout << "myList.removeDuplicates()...\n";
    myList.removeDuplicates();
    cout << endl << myList << endl;
    myList.range(myList.first());
    cout << "myList.range()\n" << myList << endl;
    List L, M;
    int n = 1 + rand() % 9;
    List::position q = L.first(), r = M.first();
    firstN(n, q, r, L, M);
    cout << "L:\n" << L << endl << "M:\n" << M << endl;
    return 0;
}
