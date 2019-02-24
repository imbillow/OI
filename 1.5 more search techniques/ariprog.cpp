/*
ID: yaagnto2
LANG: C++14
TASK: ariprog
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;
const int MaxM = 250;

vector<int> Seq;
bool BiSquares[MaxM * MaxM * 2 + 1];
int Squares[MaxM + 1];

int main() {
    uint32_t N, M;
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    fin >> N >> M;

    uint32_t MM = M * M;
    uint32_t MM2 = 2 * MM;
    uint32_t Mp1 = M + 1;
    auto _seqSize = static_cast<uint32_t>(Mp1 * Mp1 + 1);

    Seq.resize(_seqSize);

    for (int i = 1; i <= M; ++i)
        Squares[i] = i * i;

    int p, q, v;
    for (int i = 0; i <= M; ++i) {
        p = Squares[i];
        for (int j = 0; j <= M; ++j) {
            q = Squares[j];
            v = p + q;
            Seq[i * (M + 1) + j] = v;
            BiSquares[v] = true;
        }
    }

    auto _seqEnd = Seq.begin() + _seqSize;
    sort(Seq.begin(), _seqEnd);
    Seq.erase(unique(Seq.begin(), _seqEnd), Seq.end());

    int a, b;
    bool ok, exist{};
    int max_b = MM2 / (N - 1), max_a;
    for (b = 1; b <= max_b; ++b) {
        max_a = MM2 - b * (N - 1);
        for (int i = 0; i < Seq.size() && Seq[i] <= max_a; ++i) {
            a = Seq[i];
            ok = true;
            for (int n = 1; n < N; ++n) {
                if (!BiSquares[a + b * n]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                exist = true;
                cerr << a << " " << b << " found." << endl;
                fout << a << " " << b << endl;
            }
        }
    }
    if (!exist)
        fout << "NONE" << endl;
    return 0;
}

