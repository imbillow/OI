/*
ID: yaagnto2
LANG: C++14
TASK: milk2
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

struct Span {
    int left, right;

    Span(int l, int r) : left(l), right(r) {}

    int width() { return right - left; }
};

template<typename ForwardIt, typename UnaryPredicate>
std::vector<ForwardIt> find_all(ForwardIt first, ForwardIt last,
                                UnaryPredicate p) {
    std::vector<ForwardIt> res;
    for (auto it = first; it != last; ++it) {
        if (p(*it))
            res.push_back(it);
    }
    return res;
}

int main() {
    using namespace std;
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n;
    fin >> n;

    vector<Span> spans;

    for (int i = 0; i < n; i++) {
        int l, r;
        fin >> l >> r;

        auto ss = find_all(spans.begin(), spans.end(),
                           [=](Span &sp) { return sp.left <= r && sp.right >= l; });
        if (ss.empty())
            spans.emplace_back(l, r);
        else {
            for (auto real_it : ss) {
                l = min(real_it->left, l);
                r = max(real_it->right, r);
            }

            spans.erase(
                    remove_if(spans.begin(), spans.end(),
                              [&](Span &s) { return s.left >= l && s.right <= r; }),
                    spans.end());
            spans.emplace_back(l, r);
        }
    }

    sort(spans.begin(), spans.end(),
         [](Span &a, Span &b) { return a.left < b.left; });
    int maxi = max_element(spans.begin(), spans.end(),
                           [](Span &a, Span &b) { return a.width() < b.width(); })
            ->width();
    int mini = 0;
    if (spans.size() > 1) {
        vector<int> mins;
        int start = 0;

        for (auto &s : spans) {
            if (start != 0)
                mins.emplace_back(s.left - start);
            start = s.right;
        }
        mini = *max_element(mins.begin(), mins.end());
    }

    cout << maxi << " " << mini << endl;
    fout << maxi << " " << mini << endl;
    return 0;
}
