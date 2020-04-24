//  Implementation of a set of positive integers using an array of bools to indicate inclusion
#ifndef SET_H
#define SET_H

#include <iostream>

class set {
    friend std::ostream& operator<<(std::ostream& out, const set& A) {
        out << '{';
        int j = A.size();
        for (int i = 0; i < A.capacity; i++) {
            if (A.contents[i]) {
                out << i;
                if (j > 1) {
                    out << ", ";
                }
                j--;
            }
        }
        out << '}' << std::endl;
        return out;
    }

    //  Set operators
    friend set getUnion(set& A, set& B) {
        set C = A;
        for (int i = 0; i < B.capacity; i++) {
            if (B.contains(i)) C.insert(i);
        }
        return C;
    }

    friend set intersect(set& A, set& B) {
        set C;
        for (int i = 0; i < A.capacity; i++) {
            if (A.contains(i) && B.contains(i))
                C.insert(i);
        }
        return C;
    }

    friend set difference(set& A, set& B) {
        set C;
        for (int i = 0; i < A.capacity; i++) {
            if (A.contains(i) && !B.contains(i))
                C.insert(i);
        }
        return C;
    }

public:
    set();
    set(int);
    set(const set&);
    ~set();
    void init();
    bool isEmpty() const;
    bool contains(int) const;
    void insert(int);
    void remove(int);

    int size() const;
private:
    bool* contents;
    int cardinality;
    int capacity;
    //  Add a string or char tag member to allow the set to identify itself.
};

#endif // SET_H