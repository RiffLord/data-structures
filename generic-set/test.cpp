#include <iostream>
#include "set.h"

using namespace std;

int main() {
    set<int> A;
    cout << A;
    cout << "Is A empty? " << (A.isEmpty() ? "true" : "false") << endl;
    cout << "Cardinality of A: " << A.size() << endl;
    A.insert(5);
    A.insert(2);
    A.insert(6);
    cout << A;
    cout << "Is A empty? " << (A.isEmpty() ? "true" : "false") << endl;
    cout << "Cardinality of A: " << A.size() << endl;
    cout << "A contains 5 " << (A.contains(5) ? "true" : "false") << endl;
    cout << "A contains 666 " << (A.contains(666) ? "true" : "false") << endl;
    cout << "Removing 5 from A..." << endl;
    A.remove(5);
    cout << "Cardinality of A: " << A.size() << endl;
    cout << "A = " << A;
    set<int> B;
    B.insert(1);
    B.insert(2);
    B.insert(3);
    cout << "B = " << B;
    cout << "A U B = ";
    set<int> C = getUnion(A, B);
    cout << C;
    cout << "B ^ C = ";
    set<int> D = intersect(B, C);
    cout << D;
    cout << "C diff A = ";
    set<int> E = difference(A, C);
    cout << E;
    cout << "A diff B = " << difference(A, B);
    cout << "B diff A = " << difference(B, A);
}