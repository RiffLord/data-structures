/**
 * @file    test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Testing List class methods
 * @version 0.3
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "..\list.h"

int main(void) {
    using namespace std;
    List myList;
    if (myList.isEmpty()) cout << "myList.isEmpty() : true\n";
    srand(time(NULL));
    List::position p = myList.first();
    int range = 1 + rand() % 99, i;
    for (i = 0; i < range; i++) {
        myList.insert(rand() % 99, p);
        p = myList.next(p);
    }
    if (!myList.isEmpty()) cout << "myList.isEmpty() : false\n";
    List::position randPos = rand() % range;
    cout << myList.read(randPos) << endl;
    cout << endl << myList << endl;
    p = myList.first();
    for (i = 0; i < range; i++) {
        myList.write(666, p);
        p = myList.next(p);
    }
    cout << myList << endl;
    if (myList.isValid(randPos)) cout << "myList.isValid(" << p << ") : true\n";
    if (!myList.isValid(range + 79)) cout << "myList.isValid(" << range + 79 << ") : false\n";
    myList.write(42, randPos);
    cout << endl << myList << endl;
    myList.remove(randPos);
    cout << endl << myList << endl;
    List listy = myList;
    cout << "Printing listy...\n" << listy << endl;
    myList.remove(randPos);
    cout << "myList.last() : " << myList.last() << endl;
    cout << "listy.last() : " << listy.last() << endl;
    cout << "listy.previous(listy.last()) : " << listy.previous(listy.last()) << endl;
    List l1, l2;
    l1 = l2 = listy;
    cout << l1 << endl << l2 << endl;
    if (l1 == listy) cout << "l1 == listy : true" << endl;
    if (!(listy == myList)) cout << "listy == myList : false" << endl;
    if (listy != myList) cout << "listy != myList : true" << endl;
    return 0;
}
