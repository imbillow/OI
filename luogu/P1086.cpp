#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Point {
  int x, y, v;

  Point(int x, int y, int v) : x(x), y(y), v(v) {}

  int distance(const Point &o) const { return abs(x - o.x) + abs(y - o.y); }
};

int main() {
  int m, n, k;
  cin >> m >> n >> k;

  vector<Point> ps;
  int b;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      cin >> b;
      if (b != 0) {
        ps.emplace_back(i, j, b);
      }
    }
  sort(ps.begin(), ps.end(), [](Point &a, Point &b) { return a.v > b.v; });

  int a = 0, d;
  Point cur{0, 0, 0};
  for (auto &p : ps) {
    d = a == 0 ? p.x + 1 : p.distance(cur) + 1;
    if (d + p.x <= k) {
      k -= d;
    } else
      break;
    cur = p;
    a += p.v;
  }
  cout << a << endl;
  return 0;
}