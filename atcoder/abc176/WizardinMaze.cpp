#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <deque>

using namespace std;
using Vec3i = tuple<int, int, int>;

char maze[1001][1001];
unsigned h, w, ch, cw, dh, dw;
int M[1001][1001];
const int INF = 1e9;

template<class T> inline bool chmin(T &a, const T &b) {
  if (a > b) {
	a = b;
	return true;
  } else
	return false;
}

int resolve(int x, int y) {
  deque<Vec3i> path{};
  path.emplace_back(x, y, 0);

  while (!path.empty()) {
	const auto&[fx, fy, fz] = path.front();
	path.pop_front();
	if (M[fy][fx] < fz){
	  continue;
	}
	chmin(M[fy][fx], fz);
	for (int dy = -2; dy <= 2; ++dy) {
	  for (int dx = -2; dx <= 2; ++dx) {
		if (dy == 0 && dx == 0)
		  continue;
		int cx = fx + dx, cy = fy + dy;
		if (cx < 1 || cx > w || cy < 1 || cy > h || maze[cy][cx] == '#')
		  continue;
		if (abs(dx) + abs(dy) == 1) {
		  int cz = fz;
		  if (chmin(M[cy][cx], cz)) {
			path.emplace_front(cx, cy, cz);
		  }
		} else {
		  int cz = fz + 1;
		  if (chmin(M[cy][cx], cz)) {
			path.emplace_back(cx, cy, cz);
		  }
		}
	  }
	}

//	for (int y = 1; y <= H; ++y) {
//	  for (int x = 1; x <= W; ++x) {
//		cout << (M[y][x] == INT32_MAX ? -1 : M[y][x]) << "\t";
//	  }
//	  cout << "\n";
//	}
//	cout << "\n\n";
  }

  return M[dh][dw];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> h >> w >> ch >> cw >> dh >> dw;
  for (size_t y = 1; y <= h; y++) {
	for (size_t x = 1; x <= w; x++) {
	  cin >> maze[y][x];
	}
  }

  for (auto &i : M) {
	fill_n(begin(i), 1001, INF);
  }
  int v = resolve(cw, ch);
  cout << (v == INF ? -1 : v) << endl;

  return 0;
}
