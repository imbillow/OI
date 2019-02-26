/*
ID: yaagnto2
LANG: C++14
TASK: milk3
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <set>
using namespace std;
typedef tuple<int, int, int> state_t;
set<state_t> _visited;
vector<int> sol;
int A_MAX, B_MAX, C_MAX;
int A, B, C;

bool visited(const int& a, const int& b, const int& c) {
	return _visited.find(state_t{ a, b, c }) != _visited.end();
}
void pour(int& a, int& b) {
	int tmp = B_MAX - b;
	if (a <= tmp)
	{
		a = 0;
		b += tmp;
	}
	else
	{
		a -= tmp;
		b = B_MAX;
	}
}
void solve() {
	if (visited(A, B, C)) return;
	if (A == 0) {
		sol.emplace_back(C);
		_visited.insert(state_t{ A,B,C });
	}
	int a = A, b = B, c = C;
	if (A > 0)
	{
		if (B < B_MAX)
		{
			pour(A, B);
			solve();
			A = a;
			B = b;
		}
		if (C < C_MAX)
		{
			pour(A, C);
			solve();
			A = a;
			C = c;
		}
	}

	if (B > 0)
	{
		if (A < A_MAX)
		{
			pour(B, A);
			solve();
			B = b;
			A = a;
		}
		if (C < C_MAX)
		{
			pour(B, C);
			solve();
			B = b;
			C = c;
		}
	}

	if (C > 0)
	{
		if (A < A_MAX)
		{
			pour(C, A);
			solve();
			C = c;
			A = a;
		}
		if (B < B_MAX)
		{
			pour(C, B);
			solve();
			B = b;
			C = c;
		}
	}

}
int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	fin >> A_MAX >> B_MAX >> C_MAX;
	A = A_MAX;
	B = B_MAX;
	C = C_MAX;
	solve();
	for (auto i = sol.begin(); i != sol.end() - 1; ++i)
		fout << *i << " ";
	fout << *(sol.end() - 1) << endl;
	return 0;
}

