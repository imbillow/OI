/*
ID: yaagnto2
LANG: C++14
TASK: dualpal
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string conversion(int n, int base) {
  static char mapper[20]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

  string dst{};
  while (n > 0) {
    dst = mapper[n % base] + dst;
    n /= base;
  }
  return dst;
}

string str_revered(const string &o) {
  if (o.length() <= 1)
    return o;
  string r;
  for (auto i = static_cast<int>(o.length() - 1); i >= 0; --i)
    r += o[i];
  return r;
}

int main() {
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  int n, less;
  fin >> n >> less;

  for (int i = 0; i < n; ++i) {
    for (int j = less + 1; j < INT32_MAX; ++j) {
      int times = 0;
      for (int base = 2; base < 11; ++base) {
        auto origin = conversion(j, base);
        if (str_revered(origin) == origin)
          times++;
        if (times > 1) {
          less = j;
          break;
        }
      }
      if (times > 1)
        break;
    }

    fout << less << endl;
  }

  return 0;
}