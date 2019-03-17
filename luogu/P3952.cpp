#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    int l, o, d, ro;
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
        ro = d = 0;
        memset(vars, 0, 100);
        bool is = true, err = false;
        try {
            for (int j = 0, k = 0; j < l; ++j) {
                getline(cin, s);
                m = s[0];
                if (m == 'F') {
                    d++;
                    auto it = find_if(s.begin(), s.end(), [](char c) { return islower(c) && c != 'n'; });
                    if (it != s.end()) {
                        if (any_of(vars, vars + k, [=](char c) { return c == *it; })) {
                            throw exception();
                        } else {
                            vars[k++] = *it;
                        }
                    }
                    auto dp = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
                    auto np = find(s.begin(), s.end(), 'n');
                    if (np != s.end()) {
                        if (np < dp)is = false;
                        else if (d > ro && is)ro++;
                    }
                } else if (m == 'E')d--;
            }
            if (d != 0) throw exception();
        } catch (exception &_) {
            cout << "ERR" << endl;
            err = true;
        }
        if (!err) {
            if (ro == o) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}