#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

const char Wall = '#', Road = '.';
const char Dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
const char MagicDirs[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1},};
char Maze[1001][1001];
bool Visited[1001][1001]{false};
unsigned H, W, Ch, Cw, Dh, Dw;
int Magic[1001][1001];

struct Vec2i {
  int x, y;
  bool is_edge;

  Vec2i(int x_, int y_) : x(x_), y(y_), is_edge(false) {}
};

inline bool operator<(const Vec2i &lhs, const Vec2i &rhs) {
  return lhs.y < rhs.y || lhs.x < rhs.x;
}

inline bool in_range(int x, int y) {
  return x >= 1 && x <= W && y >= 1 && y <= H;
}

vector<Vec2i> get_neighbors(Vec2i p) {
  vector<Vec2i> ds{};
  int ix, iy;
  for (const char *d : Dirs) {
	ix = p.x + d[0];
	iy = p.y + d[1];
	if (in_range(ix, iy)) {
	  ds.emplace_back(ix, iy);
	}
  }
  return ds;
}

vector<Vec2i> bfs(int x, int y, int magic = 0) {
  queue<Vec2i> path;
  vector<Vec2i> nodes;
  path.push(Vec2i{x, y});
  Visited[y][x] = true;

  while (!path.empty()) {
	Vec2i t = path.front();
	path.pop();

	for (Vec2i d : get_neighbors(t)) {
	  if (!Visited[d.y][d.x]) {
		Visited[d.y][d.x] = true;
		switch (Maze[d.y][d.x]) {
		case Road:path.push(d);
		  break;
		case Wall:t.is_edge = true;
		  break;
		}
	  }
	}

	Magic[t.y][t.x] = magic;
	nodes.push_back(t);
  }
  return nodes;
}

int resolve(int x, int y) {
  queue<Vec2i> path{};
  path.push(Vec2i{x, y});

  while (!path.empty()) {
	Vec2i t = path.front();
	path.pop();
	int magic = Magic[t.y][t.x];
	vector<Vec2i> nodes = bfs(t.x, t.y, magic);
	cout << "\n" << "for " << t.y << " " << t.x << endl;
	for (size_t i = 1; i <= H; i++) {
	  for (size_t j = 1; j <= W; j++) {
		cout << Magic[i][j] << "\t";
	  }
	  cout << "\n\n";
	}

	set<Vec2i> vis{};
	for (Vec2i node : nodes) {
	  if (!node.is_edge) {
		continue;
	  }
	  for (const char *d:MagicDirs) {
		char dx = d[0], dy = d[1];
		int mx = node.x + dx, my = node.y + dy;
		int ix = mx + dx, iy = my + dy;
		Vec2i v{ix, iy};
		if (in_range(ix, iy) && Maze[my][mx] == Wall && Maze[iy][ix] != Wall && vis.find(v) == vis.end()) {
		  path.push(v);
		  vis.insert(v);
		  int m = Magic[iy][ix];
		  if (m == -1) {
			Magic[iy][ix] = magic + 1;
		  } else {
			Magic[iy][ix] = min(magic + 1, m);
		  }
		}
	  }
	}
  }

  return Magic[Dh][Dw];
}

int main() {
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
  for (size_t i = 1; i <= H; i++) {
	for (size_t j = 1; j <= W; j++) {
	  cin >> Maze[i][j];
	}
  }

  for (size_t i = 0; i <= H; i++) {
	for (size_t j = 0; j <= W; j++) {
	  cout << Maze[i][j] << "\t";
	}
	cout << "\n";
  }

  memset(Magic, -1, sizeof(Magic));
  Magic[Ch][Cw] = 0;
  cout << resolve(Cw, Ch) << endl;

  return 0;
}
