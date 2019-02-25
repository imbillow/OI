/*
ID: yaagnto2
LANG: C++14
TASK: milk3
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    int a, b, c;
    fin >> a >> b >> c;
    vector<int> sols{c, max(0, c - b)};
	

    sort(sols.begin(), sols.end());
    sols.erase(unique(sols.begin(), sols.end()), sols.end());
    for (auto i :sols) {
        fout << i << " ";
    }
    fout << endl;
    return 0;
}

