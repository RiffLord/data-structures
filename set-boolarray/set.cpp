#include <iostream>
#include <assert.h>
#include "set.h"

set::set() {
    capacity = 50;
    cardinality = 0;
    contents = new bool[capacity];
    init();
}

set::set(int n) {
    capacity = n;
    cardinality = 0;
    contents = new bool[capacity];
    init();
}

set::set(const set& A) {
    capacity = A.capacity;
    cardinality = A.cardinality;
    contents = new bool[capacity];
    for (int i = 0; i < capacity; i++)
        contents[i] = A.contents[i];
}

set::~set() { delete[] contents; }

void set::init() {
    for (int i = 0; i < capacity; i++)
        contents[i] = false;
}

bool set::isEmpty() const {
    if (cardinality == 0) return true;
    return false;
}

bool set::contains(int i) const {
    if (i >= capacity || !contents[i]) return false;
    return true;
}

void set::insert(int i) {
    assert(i < capacity);
    if (!contents[i]) {
        contents[i] = true;
        cardinality++;
    }
}

void set::remove(int i) {
    if (contents[i]) {
        contents[i] = false;
        cardinality--;
    }
}

int set::size() const { return cardinality; }