/**
 * @file      dictionary.h
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Generic dictionary data structure
 * @version   0.2
 * @date      2022-10-09
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "hash.h"
#include "list.h"

template <class T> class Dictionary {
public:
    Dictionary(unsigned int);
    ~Dictionary();
    bool isEmpty() const;
    bool belongs(const T &) const;
    T read(const T &) const;
    void insert(const T &);
    void remove(const T &);
    unsigned int size() const;
    unsigned int calculateHash(const T &) const;
    void print();
private:
    hashValue hsh;
    unsigned int length;
    unsigned int numberOfItems;
    List<T> *table;
};

template <class T>
Dictionary<T>::Dictionary(unsigned int u) {
    length = u;
    numberOfItems = 0;
    table = new List<T>[length];
}

template <class T>
Dictionary<T>::~Dictionary() { delete[] table; }

template <class T>
bool Dictionary<T>::isEmpty() const { return numberOfItems == 0; }

template <class T>
bool Dictionary<T>::belongs(const T &item) const {
    typename List<T>::position iterator;
    bool itemFound = false;
    unsigned int pos = hashValue(item);

    iterator = table[pos].first();
    while (!table[pos].endOfList(iterator) && !itemFound) {
        if (item == table[pos].read(iterator)) itemFound = true;
        else iterator = table[pos].next(iterator);
    }
    return itemFound;
}

template <class T>
void Dictionary<T>::insert(const T &item) {
    table[hashValue(item)].insert(item, table[hashValue(item)].first());
    ++numberOfItems;
}

template <class T>
void Dictionary<T>::remove(const T &item) {
    typename List<T>::position iterator;
    bool itemFound = false;
    unsigned int pos = hashValue(item);

    iterator = table[pos].first();
    while (!table[pos].endOfList(iterator) && !itemFound) {
        if (item == table[pos].read(iterator)) itemFound = true;
        else iterator = table[pos].next(iterator);
    }
    if (itemFound) {
        table[pos].remove(iterator);
        --numberOfItems;
    }
}

template <class T>
unsigned int Dictionary<T>::calculateHash(const T &key) const {
    return (hash(std::to_string(key)) % length);
}

template <class T>
unsigned int Dictionary<T>::size() const { return numberOfItems; }

template <class T>
void Dictionary<T>::print() {
    for (int i = 0; i < length; i++)
        table[i].print();
}

#endif // !DICTIONARY_H
