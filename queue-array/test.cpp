#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    queue<int> q;
    cout << "Is q empty? " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "q.size(): " << q.size() << endl;
    cout << "Populating q..." << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(42);
    q.enqueue(13);
    q.enqueue(666);
    cout << "Is q empty? " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "q.size(): " << q.size() << endl;
    printQueue(q);
    cout << "Removing items from q...\n";
    q.dequeue();
    q.dequeue();
    cout << "q.size(): " << q.size() << endl;
    printQueue(q);
    cout << "q.read(): " << q.read() << endl;        
}