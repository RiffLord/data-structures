#include <iostream>
#include <stdlib.h>
#include "queue.h"

using namespace std;

void extractPositives(queue<int>&, queue<int>&);

void extractPositives2(queue<int>&, queue<int>&);

int main(int argc, char* argv[]) {
    char* endptr;
    queue<int> input;
    queue<int> output;

    for (int i = 1; i < argc; i++)
        input.enqueue(strtol(argv[i], &endptr, 10));
    cout << "Input queue: " << input << "\nExtracting positive values..." << endl;
    extractPositives2(input, output);
    cout << "Input queue: " << input;
    cout << "Output queue: " << output;
}

//  Extracts positive values from the source q, removing them.
void extractPositives(queue<int>& source, queue<int>& target) {
    while (!source.isEmpty()) {
        int i = source.read();
        if (i > 0) target.enqueue(i);
        source.dequeue();
    }
}

//  Extracts positive values from source q, but conserves
//  its structure with the use of an auxiliary queue.
void extractPositives2(queue<int>& source, queue<int>&target) {
    queue<int> temp;
    while (!source.isEmpty()) {
        int i = source.read();
        if (i > 0) target.enqueue(i);
        source.dequeue();
        temp.enqueue(i);
    }

    while (!temp.isEmpty()) {
        source.enqueue(temp.read());
        temp.dequeue();
    }
}