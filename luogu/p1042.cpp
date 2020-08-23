#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
char D[2500 * 25];
int W1[10000], L1[10000];
int W2[10000], L2[10000];

int main() {
  char b;
  int z = 0;
  while (cin >> b && b != 'E')
    D[z++] = b;
  int i1 = 0, i2 = 0;
  for (int i = 0; i < z; ++i) {
    b = D[i];
    if (b == 'W') {
      W1[i1]++;
      W2[i2]++;
    } else {
      L1[i1]++;
      L2[i2]++;
    }

    if ((W1[i1] >= 11 || L1[i1] >= 11) && abs(W1[i1] - L1[i1]) >= 2)
      i1++;
    if ((W2[i2] >= 21 || L2[i2] >= 21) && abs(W2[i2] - L2[i2]) >= 2)
      i2++;
  }
  for (int k = 0; k <= i1; ++k)
    cout << W1[k] << ":" << L1[k] << endl;
  cout << endl;
  for (int k = 0; k <= i2; ++k)
    cout << W2[k] << ":" << L2[k] << endl;

  return 0;
}