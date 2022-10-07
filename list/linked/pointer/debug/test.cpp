/**
 * @file    test.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Testing the pointer implementation of a generic linked list data structure
 * @version 0.5
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef __linux__
    #include "../list.h"
#elif _WIN32
    #include "..\list.h"
#else
    #error Platform not supported
#endif

//  TODO:   test class with other types of data
int main(void) {
    using namespace std;
    srand(time(NULL));
    List<int> myList;
    if (myList.isEmpty()) cout << "myList.isEmpty() : true" << endl;
    if (myList.endOfList(myList.first())) cout << "endOfList(first()) : true" << endl;
    cout << "Populating list..." << endl;
    int i;
    List<int>::position p = myList.first();
    for (i = 0; i < 10; i++) {
        myList.insert(i + rand() % 89, p);
        p = myList.next(p);
    } 
    if (!myList.isEmpty()) cout << "myList.isEmpty() : false" << endl;
    if (myList.endOfList(p)) cout << "myList.endOfList(" << p << ") : true" << endl;
    if (!myList.endOfList(myList.first())) cout << "myList.endOfList(first()) : false" << endl;
    cout << myList << endl;
    p = myList.next(myList.first());

    cout << "calling read()\n" << myList.read(myList.first()) << endl;
    cout << myList.read(p) << endl << endl;
    myList.write(42, p);
    cout << "myList.getLength() : " << myList.getLength() << endl;
    cout << myList << endl;
    myList.remove(p);
    cout << "myList.getLength() : " << myList.getLength() << endl;
    cout << myList << endl;
    myList.remove(myList.first());
    cout << "myList.getLength() : " << myList.getLength() << endl;
    cout << myList << endl;
    cout << endl << "calling read on invalid position... " <<  myList.read(p) << endl;
    p = myList.next(myList.next(myList.next(myList.first())));
    myList.remove(p);
    cout << "myList.getLength() : " << myList.getLength() << endl;
    cout << myList << endl;
    p = myList.next(myList.next(myList.next(myList.first())));
    myList.insert(666, p);
    cout << "myList.getLength() : " << myList.getLength() << endl;
    cout << myList << endl;
    while (!myList.isEmpty()) {
        myList.remove(myList.first());
    }
    cout << "myList.getLength() : " << myList.getLength() << endl;

    p = myList.first();
    for (i = 0; i < 10; i++) {
        myList.insert(i + rand() % 89, p);
        p = myList.next(p);
    }
    cout << "Re-populated myList...\n" << myList << endl;
    List<int> otherList;
    List<int>::position q = otherList.first();
    otherList.insert(rand() % 99, q);
    otherList.insert(rand() % 99, q);
    otherList.insert(rand() % 99, q);
    cout << "otherList:" << endl << otherList << endl;
    cout << "otherList.getLength() : " << otherList.getLength() << endl;
    if (otherList != myList) cout << "otherList != myList : true" << endl;
    if (!(otherList == myList)) cout << "otherList == myList : false" << endl;
    //cout << "Assigning otherList to myList..." << endl;
//    myList = otherList;
    //cout << "myList after using overloaded assignment operator...\n" << myList << endl;
    if (!(otherList != myList)) cout << "otherList != myList : false" << endl;
    if (otherList == myList) cout << "otherList == myList : true" << endl;
    p = myList.first();
    cout << myList.read(p) << endl;
    for (i = 0; i < 10; i++) {
        myList.insert(i + rand() % 89, p);
        p = myList.next(p);
    }
    cout << "myList after expanding with new data...\n" << myList << endl;
    //cout << "Assigning otherList to myList..." << endl;
    //myList = otherList;
  
    return 0;
}
