#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  unsigned N;
  vector<int> A{};
  cin >> N;
  A.resize(N);
  for (size_t i = 0; i < N; i++) {
    cin >> A[i];
  }

  uint64_t stools = 0;
  int a, b;
  for (size_t i = 1; i < N; i++) {
    a = A[i];
    b = A[i - 1];
    stools += max(0, b - a);
    A[i] = max(b, a);
  }
  cout << stools << endl;
  return 0;
}
