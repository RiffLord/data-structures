/**
 * @file        hash.cpp
 * @author      Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief       Implementation file for a hash function library
 * @version     0.1
 * @date        2022-10-07
 * 
 * @copyright   NO Copyright !(c) 2022
 * 
 */
#include <cstdlib>
#include <iostream>
#include "hash.h"

hashValue hash(std::string str) {
    hashValue hash = 5381;
    int l = str.length();
    int c;
    for (int i = 0; i < l; i++) {
        int c = str[i];
        hash = hash * 33 + c;
    }
    return hash;
}
