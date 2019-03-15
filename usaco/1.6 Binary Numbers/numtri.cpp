/*
ID: yaagnto2
LANG: C++14
TASK: numtri
*/
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int MAX_R = 1000;
int Triangle[MAX_R + 1][MAX_R + 1];
int R;
int MaxV;

int sol(int k, int r, int c) {
    if (r > R)return k;
    for (int x = c; x <= c + 1; ++x) {
        auto kk = sol(k + Triangle[r][x], r + 1, x);
        MaxV = max(MaxV, kk);
    }
    return MaxV;
}

auto main() -> int {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    fin >> R;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= i; ++j) {
            fin >> Triangle[i][j];
        }
    }
    sol(0, 1, 1);
    fout << MaxV << endl;
    return 0;
}
