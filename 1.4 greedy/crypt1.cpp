/*
ID: yaagnto2
LANG: C++14
TASK: crypt1
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef int digit_t;
int n;
vector<digit_t> digits{};

vector<int> gen_all_numbers__(vector<int> &seed, vector<int> &opts, size_t len, size_t pos = 1) {
    if (pos == len)
        return seed;

    vector<int> nums{};
    for (auto o:seed)
        for (auto digit:opts)
            nums.emplace_back(o * 10 + digit);
    return gen_all_numbers__(nums, opts, len, pos + 1);
}

vector<int> gen_all_numbers(vector<int> &seed, size_t len) {
    return gen_all_numbers__(seed, seed, len);
}

bool number_check(digit_t num, size_t limit) {
    if (num >= pow(10, limit))
        return false;
    auto c{num};
    while (c > 0) {
        if (!binary_search(digits.begin(), digits.end(), c % 10)) {
            return false;
        }
        c /= 10;
    }

    return true;
}

int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        digit_t t;
        fin >> t;
        digits.emplace_back(t);
    }
    sort(digits.begin(), digits.end());

    size_t ans{};
    auto ns = gen_all_numbers(digits, 3);
    for (auto fst:ns) {
        vector<digit_t> sec_digits{digits};
        sec_digits.erase(
                remove_if(sec_digits.begin(), sec_digits.end(),
                          [=](digit_t a) { return !number_check(fst * a, 3); }),
                sec_digits.end());

        if (!sec_digits.empty()) {
            for (auto sec:gen_all_numbers(sec_digits, 2)) {
                if (number_check(fst * sec, 4)) {
                    ans++;
                }
            }
        }
    }
    fout << ans << endl;
    return 0;
}