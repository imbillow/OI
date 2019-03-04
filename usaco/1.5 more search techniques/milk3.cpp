/*
ID: yaagnto2
LANG: C++14
TASK: milk3
*/
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef tuple<int, int, int> state_t;
set<state_t> _visited;
vector<int> sol;
int A_MAX, B_MAX, C_MAX;
int A, B, C;

bool visited(const int& a, const int& b, const int& c)
{
	return _visited.find(state_t{a, b, c}) != _visited.end();
}

void pour(int& a, int& b, int& b_max)
{
	if (a + b <= b_max)
	{
		b += a;
		a = 0;
	}
	else
	{
		a -= b_max - b;
		b = b_max;
	}
}

void solve()
{
	if (visited(A, B, C))
		return;
	if (A == 0)
	{
		cout << A << "\t" << B << "\t" << C << "\t" << endl;
		sol.emplace_back(C);
		_visited.insert(state_t{A, B, C});
	}
	int a = A, b = B, c = C;
	if (A > 0)
	{
		if (B < B_MAX)
		{
			pour(A, B, B_MAX);
			solve();
			A = a;
			B = b;
		}
		if (C < C_MAX)
		{
			pour(A, C, C_MAX);
			solve();
			A = a;
			C = c;
		}
	}

	if (B > 0)
	{
		if (A < A_MAX)
		{
			pour(B, A, A_MAX);
			solve();
			B = b;
			A = a;
		}
		if (C < C_MAX)
		{
			pour(B, C, C_MAX);
			solve();
			B = b;
			C = c;
		}
	}

	if (C > 0)
	{
		if (A < A_MAX)
		{
			pour(C, A, A_MAX);
			solve();
			C = c;
			A = a;
		}
		if (B < B_MAX)
		{
			pour(C, B, B_MAX);
			solve();
			B = b;
			C = c;
		}
	}
}

auto main() -> int
{
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	fin >> A_MAX >> B_MAX >> C_MAX;
	A = B = 0;
	C = C_MAX;
	solve();
	if (!sol.empty())
	{
		for (auto i = sol.begin(); i != sol.end() - 1; ++i)
			fout << *i << " ";
		fout << *(sol.end() - 1) << endl;
	}
	return 0;
}
