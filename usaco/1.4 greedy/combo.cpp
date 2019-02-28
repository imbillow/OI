/*
ID: yaagnto2
LANG: C++14
TASK: combo
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <numeric>

using namespace std;
typedef array<int, 3> combination_t;
int n;

int real_mod(int k, int limit) {
    if (k <= limit && k > 0)
        return k;
    if (k > limit)
        return k % limit;
    return limit + k;
}

vector<combination_t> permutations(combination_t com, vector<combination_t> sol = {}, size_t pos = 0) {
    if (pos == com.size())
        return sol;
    auto val = com[pos];
    vector<int> vec(5);
    iota(vec.begin(), vec.end(), val - 2);
    transform(vec.begin(), vec.end(), vec.begin(),
              [](int i) { return real_mod(i, n); });

    vector<combination_t> dst{};
    for (auto v:vec) {
        if (sol.empty()) {
            dst.push_back(combination_t{v, 0, 0});
        } else {
            for (auto &s:sol) {
                auto tmp{s};
                tmp[pos] = v;
                dst.push_back(tmp);
            }
        }
    }
    return permutations(com, dst, pos + 1);
}

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    fin >> n;
    combination_t custom{}, master{};
    for (int i = 0; i < 3; ++i)
        fin >> custom[i];
    for (int i = 0; i < 3; ++i)
        fin >> master[i];
    if (n > 5) {
        auto cp = permutations(custom);
        auto mp = permutations(master);
        sort(cp.begin(), cp.end());
        sort(mp.begin(), mp.end());

        vector<combination_t> res;
        set_union(cp.begin(), cp.end(),
                  mp.begin(), mp.end(),
                  back_inserter(res));

        fout << res.size() << endl;
    } else {
        fout << n * n * n << endl;
    }
    return 0;
}