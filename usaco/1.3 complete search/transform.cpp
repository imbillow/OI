/*
ID: yaagnto2
LANG: C++14
TASK: transform
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
char square[10][10];
char translated[10][10];
int n;

bool array_equals(char a[][10], char b[][10]) {
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      if (a[x][y] != b[x][y])
        return false;
    }
  }
  return true;
}

void array_print(char a[][10]) {
  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }
}

void reflection(char out[][10], char in[][10]) {
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < n; ++y)
      out[x][y] = in[x][n - y - 1];
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  fin >> n;
  for (int i = 0; i < n; ++i)
    fin >> square[i];
  for (int i = 0; i < n; ++i)
    fin >> translated[i];

  int ans;

  char d90[10][10];
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < n; ++y)
      d90[x][y] = square[n - y - 1][x];
  if (array_equals(translated, d90)) {
    ans = 1;
    goto output;
  }

  char d180[10][10];
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < n; ++y)
      d180[x][y] = square[n - x - 1][n - y - 1];
  if (array_equals(translated, d180)) {
    ans = 2;
    goto output;
  }

  char d270[10][10];
  for (int x = 0; x < n; ++x)
    for (int y = 0; y < n; ++y)
      d270[x][y] = square[y][n - x - 1];
  if (array_equals(translated, d270)) {
    ans = 3;
    goto output;
  }

  char ref[10][10];
  reflection(ref, square);
  if (array_equals(translated, ref)) {
    ans = 4;
    goto output;
  }

  for (auto t : {d90, d180, d270}) {
    char combination[10][10];
    reflection(combination, t);
    if (array_equals(translated, combination)) {
      ans = 5;
      goto output;
    }
  }

  if (array_equals(square, translated)) {
    ans = 6;
    goto output;
  }

  ans = 7;

output:
  fout << ans << endl;
  return 0;
}