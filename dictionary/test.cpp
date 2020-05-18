#include <iostream>
#include <string>
#include "dictionary.h"
#include "linked_list.h"

using namespace std;

int main() {
    dictionary<string> dic;
    dictionary_item<string> strArray[10];
    int i;
    
    strArray[0].setAttribute("A");
    strArray[1].setAttribute("B");
    strArray[2].setAttribute("C");
    strArray[3].setAttribute("D");
    strArray[4].setAttribute("E");
    strArray[5].setAttribute("F");
    strArray[6].setAttribute("G");
    strArray[7].setAttribute("H");
    strArray[8].setAttribute("A5");
    strArray[9].setAttribute("A4");

    for (i = 0; i < 10; i++) {
        cout << "HashFunction: " << HashFunction(strArray[i]);
        cout << endl;        
    }

    for (i = 0; i < 10; i++) dic.insert(strArray[i]);

    cout << endl << endl;
    cout << "HashFunction(A): " << HashFunction(strArray[1]) << endl << endl;

    cout << "Dictionary: " << endl;
    print(&dic);

    cout << "search(F): " << search<string>(&dic, "F") << endl;
    if (search<string>(&dic, "F") != NULL)
        cout << "contains: " << search<string>(&dic, "F")->getKey() << ' ';
    else cout << "Not found..." << endl;

    cout << "read: " << dic.read(2);
    cout << endl;
}
