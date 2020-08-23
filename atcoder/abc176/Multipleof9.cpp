#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  uint64_t sum = 0;
  for (char c : s) {
    sum += c - '0';
  }
  if (sum % 9) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
