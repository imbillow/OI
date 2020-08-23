#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int rain = 0, result = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'R')
      rain += 1;
    else {
      result = max(result, rain);
      rain = 0;
    }
  }
  result = max(result, rain);
  cout << result << endl;
  return 0;
}
