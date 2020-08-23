#include <iostream>
#include <string>
using namespace std;

uint64_t L[101];

int main() {
  int N;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> L[i];
  }

  uint64_t result = 0, a, b, c;
  for (size_t i = 0; i < N - 2; i++) {
    a = L[i];
    for (size_t j = i + 1; j < N - 1; j++) {
      b = L[j];
      if (a == b) {
        continue;
      }
      for (size_t k = j + 1; k < N; k++) {
        c = L[k];
        if (b == c || a == c) {
          continue;
        }
        if (a + b > c && a + c > b && b + c > a) {
          result++;
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}
