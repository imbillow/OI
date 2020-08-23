#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>

using namespace std;

int64_t fast_pow(int64_t a, int64_t b, int64_t c) {
  int e = 1;
  while (b > 0) {
    if (b & 1) {
      e *= a;
      e %= c;
    }
    a *= a;
    a %= c;
    b >>= 1;
  }
  return e % c;
}

int main() {
  int64_t b, p, k;
  cin >> b >> p >> k;
  int64_t d = fast_pow(b, p, k);
  printf("%ld^%ld mod %ld=%ld", b, p, k, d);
  return 0;
}