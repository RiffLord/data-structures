#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <iomanip>
#include <string>
#include "linked_list.h"
#include "util.h"

#define SIZE 100

template<class T>
class dictionary_item {
public:
    dictionary_item() {}
    ~dictionary_item() {}
    std::string getKey() const { return getAttribute(); }
    std::string getAttribute() const { return attribute; }
    void setAttribute(T attr) { attribute = attr; } 

private:
    T attribute;    //  Key attribute
};

template<class T>
class dictionary {
public:
    dictionary();
    ~dictionary();
    void init();
    bool contains(dictionary_item<T>) const;
    void insert(dictionary_item<T>);
    void remove(dictionary_item<T>);
    linked_list<dictionary_item<T>*>* read(int);
    void update(dictionary_item<T>, dictionary_item<T>);
private:
    linked_list<dictionary_item<T>*> hashTable[SIZE];
};

template<class T>
dictionary<T>::dictionary() { init(); }

template<class T>
dictionary<T>::~dictionary() {}

template<class T>
void dictionary<T>::init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i].init();
}

template<class T>
bool dictionary<T>::contains(dictionary_item<T> item) const {
    int pos = HashFunction(item); 
    if (hashTable[pos].isEmpty()) return false;
    else {
        node<dictionary_item<T>*>* temp = hashTable[pos].first();
        while (item.getKey() > hashTable[pos].read(temp).getKey() && temp != NULL) {
            temp = hashTable[pos].next(temp);
        }

        if (temp == NULL) return false;
        else {
            if (hashTable[pos].read(temp).getKey() == item.getKey())
                return true;
            else
                return false;
        }
    }
}

template<typename T>
void InsOrdine(linked_list<T>* L, T elem)
{
    node<T>* pos = L->first();
    while(!L->end(pos) && elem->getKey() > L->read(pos)->getKey()) {
        pos = L->next(pos);
    }
    L->insert(elem,pos);
}

template<class T>
void dictionary<T>::insert(dictionary_item<T> item) {
    int pos = HashFunction(item);
    dictionary_item<T>* newItem = new dictionary_item<T>;

    T attribute = item.getAttribute();
    newItem->setAttribute(attribute);
    //  Rename this
    InsOrdine(&hashTable[pos], newItem);

    std::cout << "Got here\n";
}

template<class T>
void dictionary<T>::remove(dictionary_item<T> item) {
    int pos = HashFunction(item);

    if (!hashTable[pos].isEmpty()) {
        node<dictionary_item<T>*>* temp = hashTable[pos].first();
        while (item.getKey() > hashTable[pos].read(temp).getKey() && temp != NULL) {
            temp = hashTable[pos].next(temp);
        }

        if (temp != NULL)
            if (hashTable[pos].read(temp).getKey() == item.getKey())
                hashTable[pos].remove(temp);
    }
}

template<class T>
linked_list<dictionary_item<T>*>* dictionary<T>::read(int pos) {
    //  Returns the address containing the specified position of the hashtable
    return &hashTable[pos];
}

template<class T>
void dictionary<T>::update(dictionary_item<T> oldValue, dictionary_item<T> updatedValue) {
    remove(oldValue);
    insert(updatedValue);
}

template<class T>
int HashFunction(dictionary_item<T> item) {
    //  Position in % n
    int n = 0;
    
    for (int i = 0; item.getKey()[i] != '\0'; i++) {
        n = (((int) item.getKey()[i])*(i + 1)) + n;
    }

    int modulo = n - SIZE;

    for (int i = 0; modulo > 0; i++) modulo = modulo - SIZE;

    modulo = SIZE + modulo;

    return modulo;
}

//===================== Utility functions ========================

template<class T>
dictionary_item<T>* search(dictionary<T>*, T);

template<class T>
void print(dictionary<T>&);

//  Utility function definitions

template<class T>
dictionary_item<T>* search(dictionary<T>* D, T key) {
    dictionary_item<T> item;
    item.setAttribute(key);
    int pos = HashFunction(item);
    linked_list<dictionary_item<T>*>* L = D->read(pos);
    node<dictionary_item<T>*>* temp;
    if (L != NULL) {
        if (!L->isEmpty()) {
            temp = L->first();

            while (temp != NULL) {
                if (L->read(temp)->getKey() == item.getKey())
                    return temp->getData();

                temp = L->next(temp);
            }
        }
    }

    if (temp != NULL) return temp->getData();
    else return NULL;
}

template<class T>
void print(dictionary<T>* D) {
    for (int i = 0; i < SIZE; i++) {
        if (!D->read(i)->isEmpty()) {
            std::cout << i << ' ';
            std::cout << D->read(i);
        }
    }
    std::cout << std::endl;
}

#endif // DICTIONARY_H