/*
ID: yaagnto2
LANG: C++14
TASK: barn1
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Span {
  int left, right;

  Span(int l, int r) : left(l), right(r) {}

  int width() const { return right - left; }
};

template <class InputIt, class OutputIt, class BinaryOperation>
OutputIt adjacent(InputIt first, InputIt last, OutputIt d_first,
                  BinaryOperation op) {
  if (first == last)
    return d_first;

  auto prev = *first;
  while (++first != last) {
    auto val = *first;
    *d_first++ = op(val, std::move(prev));
    prev = std::move(val);
  }
  return ++d_first;
}

int main() {
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");
  int m, s, c;
  fin >> m >> s >> c;

  vector<int> nums(static_cast<unsigned long>(c));
  for (int i = 0; i < c; ++i)
    fin >> nums[i];

  sort(nums.begin(), nums.end());

  vector<Span> spans;
  int t{}, last{};
  for (int i = 0; i < c; ++i) {
    last = t;
    t = nums[i];
    if (last != 0 && t - last == 1) {
      (spans.end() - 1)->right = t;
    } else {
      spans.emplace_back(t, t);
    }
  }

  vector<int> adj(spans.size() - 1);
  adjacent(spans.begin(), spans.end(), adj.begin(),
           [](const Span &a, const Span &b) { return a.left - b.right; });

  while (spans.size() > m) {
    auto mini = min_element(adj.begin(), adj.end());
    auto i = distance(adj.begin(), mini);
    spans[i + 1].left = spans[i].left;
    spans.erase(spans.begin() + i);
    adj.erase(adj.begin() + i);
  }

  fout << accumulate(
              spans.begin(), spans.end(), 0,
              [](const int &a, const Span &b) { return a + b.width() + 1; })
       << endl;

  return 0;
}