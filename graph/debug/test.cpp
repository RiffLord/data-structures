/**
 * @file      test.cpp
 * @author    Bruno Pezer
 * @brief     Testing the graph implementation
 * @version   0.1
 * @date      2022-10-20
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#include <iostream>
#ifdef __linux__
    #include "../graph.h"
#elif _WIN32
    #include "..\graph.h"
#else
    #error Platform not supported
#endif

int main(void) {
    using namespace std;
    return 0;
}
