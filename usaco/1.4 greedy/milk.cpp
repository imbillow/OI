/*
ID: yaagnto2
LANG: C++14
TASK: milk
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Farmer {
  int price, amount;
};

int main() {
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  int wants, n;
  fin >> wants >> n;
  vector<Farmer> farmers(static_cast<unsigned long>(n));

  for (int i = 0; i < n; ++i) {
    auto cur = &farmers[i];
    fin >> cur->price >> cur->amount;
  }
  sort(farmers.begin(), farmers.end(),
       [](Farmer &a, Farmer &b) { return a.price < b.price; });

  int cost{}, k{};

  for (auto &farmer : farmers) {
    k = min(farmer.amount, wants);
    cost += k * farmer.price;
    wants -= k;
    if (wants == 0)
      break;
  }
  fout << cost << endl;
  return 0;
}