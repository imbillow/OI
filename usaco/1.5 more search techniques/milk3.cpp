/*
ID: yaagnto2
LANG: C++14
TASK: milk3
*/
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
bool _visited[21][21][21];
bool sol[21];
int A_MAX, B_MAX, C_MAX;

void solve(int a, int b, int c) {
  if (_visited[a][b][c])
    return;
  _visited[a][b][c] = true;
  if (a == 0)
    sol[c] = true;
  if (a > 0) {
    if (a + b > B_MAX)
      solve(a + b - B_MAX, B_MAX, c);
    else
      solve(0, a + b, c);

    if (a + c > C_MAX)
      solve(a + c - C_MAX, b, C_MAX);
    else
      solve(0, b, a + c);
  }

  if (b > 0) {
    if (a + b > A_MAX)
      solve(A_MAX, a + b - A_MAX, c);
    else
      solve(a + b, 0, c);

    if (b + c > C_MAX)
      solve(a, b + c - C_MAX, C_MAX);
    else
      solve(a, 0, b + c);
  }

  if (c > 0) {
    if (a + c > A_MAX)
      solve(A_MAX, b, a + c - A_MAX);
    else
      solve(a + c, b, 0);

    if (b + c > B_MAX)
      solve(a, B_MAX, b + c - B_MAX);
    else
      solve(a, b + c, 0);
  }
}

auto main() -> int {
  ifstream fin("milk3.in");
  ofstream fout("milk3.out");
  fin >> A_MAX >> B_MAX >> C_MAX;
  solve(0, 0, C_MAX);
  string ans{};
  for (int i = 0; i < 21; ++i)
    if (sol[i])
      ans += to_string(i) + " ";
  fout << ans.substr(0, ans.length() - 1) << endl;
  return 0;
}
