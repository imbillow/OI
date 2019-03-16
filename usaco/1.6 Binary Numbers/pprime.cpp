/*
ID: yaagnto2
LANG: C++14
TASK: pprime
*/
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool prime(int i);

vector<int> palindrome(int l, int h);

vector<int> get_palindrome(int i, int len, const vector<int> &w);

int int_len(int v);

auto main() -> int {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a, b;
    fin >> a >> b;
    for (auto i:palindrome(a, b)) {
        if (prime(i))
            fout << i << endl;
    }
    return 0;
}


bool prime(int i) {
    if (i % 2 == 0)return false;
    else {
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0)return false;
        }
    }
    return true;
}


vector<int> palindrome(int l, int h) {
    vector<int> result{};
    for (int i = int_len(l); i <= int_len(h); ++i) {
        auto r = get_palindrome(0, i, vector<int>());
        result.insert(result.end(), r.begin(), r.end());
    }
    auto low = find_if(result.begin(), result.end(), [=](auto v) { return v >= l; });
    auto hi = find_if(result.begin(), result.end(), [=](auto v) { return v > h; });
    return vector<int>(low, hi);
}

int int_len(int v) {
    int i = 0;
    while (v >= 1) {
        v /= 10;
        i++;
    }
    return i;
}

vector<int> get_palindrome(int i, int len, const vector<int> &w) {
    if (i >= len / 2.0)return w;
    vector<int> nw{};
    auto p = len - 1 - i != i ?
             pow(10, i) + pow(10, len - 1 - i) :
             pow(10, i);
    if (w.empty()) {
        for (int j = 1; j <= 9; j += 2) {
            nw.emplace_back(j * p);
        }
    } else {
        for (auto k:w) {
            for (int j = 0; j <= 9; ++j) {
                nw.emplace_back(k + j * p);
            }
        }
    }
    return get_palindrome(i + 1, len, nw);
}




