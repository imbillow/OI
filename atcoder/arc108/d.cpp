#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;
const string S[4] = {"AA", "AB", "BA", "BB"};
int N;
char C[4];

string str_insert(const string &str, const size_t ind, const char c) {
  stringstream ss;
  ss << str.substr(0, ind + 1) << c << str.substr(ind + 1);
  return ss.str();
}

set<string> search(const int k) {
  set<string> tmps{}, ps{"AB"};
  for (int jk = 2; jk < k; ++jk) {
	for (const auto &str : ps) {
	  for (int i = 0; i < 4; ++i) {
		const string s = S[i];
		const char c = C[i];
		size_t m = str.find(s);
		while (m != string::npos) {
		  tmps.insert(str_insert(str, m, c));
		  m = str.find(S[i], m + 1);
		}
	  }
	}

	ps = tmps;
	tmps = {};
  }
  return ps;
}

int main() {
  cin >> N;
  for (char &i : C)
	cin >> i;
  auto vs = search(N);
//  for (const auto &s:vs) {
//	cerr << s << "\n";
//  }
  cout << vs.size() % (1000000000 + 7) << endl;
  return 0;
}
