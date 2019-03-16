/*
ID: yaagnto2
LANG: C++14
TASK: sprime
*/
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;
const int MAX_N = 100000000;

unordered_map<int, int8_t> Cache;
map<int, vector<int>> Primes;

bool is_prime(int i) {
    auto v = Cache.find(i);
    if (v != Cache.end())return v->second == 1;

    if (i < 2 || (i % 2 == 0 && i > 2)) {
        Cache[i] = 0;
        return false;
    } else {
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                Cache[i] = 0;
                return false;
            }
        }
    }

    Cache[i] = 1;
    return true;
}

vector<int> super_prime(int i, int end) {
    if (i > end) return Primes[end];

    vector<int> primes{};
    if (i == 1) {
        for (int j = 0; j < pow(10, i); ++j) {
            if (is_prime(j))primes.emplace_back(j);
        }
    } else {
        auto b = Primes[i - 1];
        for (auto p:b) {
            for (int j = 1; j < 10; ++j) {
                auto v = p * 10 + j;
                if (is_prime(v))primes.emplace_back(v);
            }
        }
    }
    Primes[i] = primes;
    return super_prime(i + 1, end);
}

auto main() -> int {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    int L;
    fin >> L;
    for (auto i:super_prime(1, L)) {
        fout << i << endl;
    }
    return 0;
}

