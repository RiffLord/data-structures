/**
 * @file      test.cpp
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Testing and debugging the dictionary data structure
 * @version   0.1
 * @date      2022-10-09
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <iostream>
#ifdef __linux__
    #include "../dictionary.h"
#elif _WIN32
    #include "..\dictionary.h"
#else
    #error Platform not supported
#endif

int main(void) {
    using namespace std;
    Dictionary<char> dic = Dictionary<char>(5);
    if (dic.isEmpty()) cout << "dic.isEmpty() : true" << endl;
    return 0;
}
