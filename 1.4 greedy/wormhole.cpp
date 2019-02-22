/*
ID: yaagnto2
LANG: C++14
TASK: wormhole
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
const int MAX_N = 13;
int N, X[MAX_N], Y[MAX_N];
int partner[MAX_N];
int on_right[MAX_N];

bool is_cycle() {
    for (int x = 1; x <= N; ++x) {
        int p = x;
        for (int y = 0; y < N; ++y) {
            p = on_right[partner[p]];
        }
        if (p != 0)
            return true;
    }
    return false;
}

int solve() {
    int total = 0;

    int x = 1;
    for (; x <= N; x++)
        if (partner[x] == 0)break;

    if (x > N) {
        if (is_cycle())
            return 1;
        else return 0;
    }

    for (int y = x + 1; y <= N; ++y)
        if (partner[y] == 0) {
            partner[x] = y;
            partner[y] = x;
            total += solve();
            partner[x] = partner[y] = 0;
        }
    return total;
}

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> N;
    for (size_t i = 1; i <= N; i++)
        fin >> X[i] >> Y[i];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Y[i] == Y[j] && X[i] < X[j])
                if (on_right[i] == 0 || X[j] < X[on_right[i]])
                    on_right[i] = j;
        }
    }
    fout << solve() << endl;
    return 0;
}
