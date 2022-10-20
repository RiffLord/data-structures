/**
 * @file      test.cpp
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Testing and debugging the dictionary data structure
 * @version   0.2
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
    dic.insert('l');
    dic.insert('f');
    dic.insert('a');
    dic.insert('%');
    dic.insert('d');
    if (!dic.isEmpty()) cout << "dic.isEmpty() : false" << endl;
    if (dic.belongs('%'))
        cout << "dic.belongs(%) : true" << endl;
    if (!dic.belongs('@')) cout << "dic.belongs(@) : false" << endl;
    cout << "dic.size() : " << dic.size() << endl;
    cout << "dic.calculateHash(@) : " << dic.calculateHash('@') << endl;
    dic.print();
    cout << "calling dic.remove(\'d\')..." << endl;
    dic.remove('d');
    cout << "dic.size() : " << dic.size() << std::endl;
    dic.print();
        List<int> l;
    List<int>::position p = l.first();
    l.insert(1, p);
    p = l.next(p);
    l.insert(2, p);
    p = l.next(p);
    l.insert(3, p);
    //cout << l << endl;
    l.print();
    return 0;
}
