/*
ID: yaagnto2
LANG: C++14
TASK: skidesign
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

const int MAX_N = 1001;
int N;
int Hs[MAX_N];


int solve() {
    int total = 0;
    int v{}, high{}, mini = INT_MAX;
    auto _minmax = minmax_element(begin(Hs), end(Hs));
    for (int low = *_minmax.first; low <= *_minmax.second - 17; ++low) {
        high = low + 17;
        total = 0;
        for (int i = 1; i <= N; ++i) {
            v = Hs[i];
            if (v < low)
                total += (int) pow(low - v, 2);
            else if (v > high)
                total += (int) pow(v - high, 2);
        }
        mini = min(mini, total);
    }

    return mini;
}

int main() {
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    fin >> N;
    for (int i = 1; i <= N; ++i) {
        fin >> Hs[i];
    }

    fout << solve() << endl;
    return 0;
}

