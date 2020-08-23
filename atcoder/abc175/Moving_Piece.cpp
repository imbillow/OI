#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

uint64_t P[5001];
int64_t C[5001], PC[5001][5001];

int main() {
  uint64_t N, K;
  cin >> N >> K;
  for (size_t i = 1; i <= N; i++) {
    cin >> P[i];
  }
  for (size_t i = 1; i <= N; i++) {
    cin >> C[i];
  }

  for (size_t i = 1; i <= N; i++) {
    size_t m = 1, n = i;
    do {
      size_t next = P[n];
      PC[i][m] = PC[i][m - 1] + C[next];
      m++;
      n = next;
    } while (n != i);
  }

  return 0;
}
