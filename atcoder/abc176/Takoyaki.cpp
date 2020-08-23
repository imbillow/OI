#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, X, T;
  cin >> N >> X >> T;
  int nTimes = ceil((float)N / X);
  cout << nTimes * T << endl;
  return 0;
}
