/**
 * @file        hash.h
 * @author      Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief       Definition file for a hash function library
 * @version     0.1
 * @date        2022-10-07
 * 
 * @copyright   NO Copyright !(c) 2022
 * 
 */
#include <cstdlib>
#include <string>

typedef unsigned int hashValue;

hashValue hash(std::string);
