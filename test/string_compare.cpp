//
// Created by billow on 19-2-15.
//

#include <iostream>

using namespace std;

int main() {
    string a{"abc"}, b{"aef"};
    cout << a.compare(0, 2, b.substr(0, 2)) << endl;
    cout << b.compare(a) << endl;
    return 0;
}