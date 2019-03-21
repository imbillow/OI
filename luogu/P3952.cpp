#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int l, o, d, ro, ro_tmp;
    string s;
    size_t pos, ob, oe;
    char m;
    char vars[100];
    for (int i = 0; i < n; ++i) {
        cin >> l >> s;
        pos = s.find('n');
        if (pos == string::npos)o = 0;
        else {
            ob = pos + 2;
            oe = s.find(')');
            o = stoi(s.substr(ob, oe - ob));
        }
        getchar();
        ro_tmp = ro = d = 0;
        memset(vars, 0, 100);
        bool is = true, err = false;
        try {
            for (int j = 0, k = 0; j < l; ++j) {
                getline(cin, s);
//                cerr << "input:\n" << s << "\n";
                m = s[0];
                if (m == 'F') {
                    d++;
                    auto it = find_if(s.begin(), s.end(), [](char c) { return islower(c) && c != 'n'; });
                    if (it != s.end()) {
                        if (any_of(vars, vars + k, [=](char c) { return c == *it; })) {
                            cerr << "var " << *it << " had exist" << "\n";
                            throw exception();
                        } else {
                            vars[d] = *it;
                        }
                    }
                    auto const_pos = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
                    auto n_pos = find(s.begin(), s.end(), 'n');
                    if (n_pos != s.end()) {
                        if (n_pos < const_pos)is = false;
                        else if (d > ro_tmp && is)ro_tmp++;
                    }
                } else if (m == 'E') {
                    vars[d] = 0;
                    d--;
                }
                ro = max(ro, ro_tmp);
                cerr << "O(n^" << ro << "\n";
                cerr << "tmp O(n^" << ro_tmp << "\n";
                if (d == 0) ro_tmp = 0;
            }
            if (d != 0) throw exception();
        } catch (exception &_) {
            cout << "ERR" << endl;
            err = true;
        }
        if (!err) {
            cerr << "finial O(n^" << ro << ")" << "\n";

            if (ro == o) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}