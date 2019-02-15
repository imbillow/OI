/*
ID: yaagnto2
LANG: C++14
TASK: palsquare
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
char mapper[20]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string conversion(int n, int base) {
    string dst{};
    while (n > 0) {
        dst = mapper[n % base] + dst;
        n /= base;
    }
    return dst;
}

string str_revered(const string &o) {
    if (o.length() <= 1)
        return o;
    string r;
    for (auto i = static_cast<int>(o.length() - 1); i >= 0; --i)
        r += o[i];
    return r;
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int B{};

    fin >> B;

    for (int i = 1; i <= 300; ++i) {
        string n = conversion(i * i, B);
        string r = str_revered(n);
        if (r == n)
            fout << conversion(i, B) << " " << r << endl;
    }

    return 0;
}