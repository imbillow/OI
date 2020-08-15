#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int
main()
{
  int64_t X, K, D;
  cin >> X >> K >> D;

  lldiv_t divmod = lldiv(X, D);
  int64_t quot_abs = abs(divmod.quot);
  int64_t result;
  if (K < quot_abs) {
    result = X >= 0 ? X - D * K : X + D * K;
  } else {
    if ((K - quot_abs) % 2 == 0) {
      result = divmod.rem;
    } else {
      result = X >= 0 ? divmod.rem - D : divmod.rem + D;
    }
  }
  cout << abs(result) << endl;
  return 0;
}
