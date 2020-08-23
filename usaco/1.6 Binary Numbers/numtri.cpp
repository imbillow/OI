/*
ID: yaagnto2
LANG: C++14
TASK: numtri
*/
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;
const int MAX_R = 1001;
int Triangle[MAX_R][MAX_R];
int Cache[MAX_R][MAX_R];
int R;

int dfs(int r, int c) {
  if (Cache[r][c] != -1)
    return Cache[r][c];
  else if (r <= R)
    return Cache[r][c] = max(dfs(r + 1, c), dfs(r + 1, c + 1)) + Triangle[r][c];
  else
    return 0;
}

auto main() -> int {
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  fin >> R;
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= i; ++j) {
      fin >> Triangle[i][j];
    }
  }
  memset(Cache, -1, sizeof(int) * MAX_R * MAX_R);
  fout << dfs(1, 1) << endl;
  return 0;
}
