#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int p1, p2, p3;
    string s, ns;
    cin >> p1 >> p2 >> p3 >> s;
    char a, b, x;
    string xs, xss;
    size_t end = s.length() - 1;
    for (size_t i = 0; i <= end; ++i) {
        b = s[i];
        if (i >= 2 && s[i - 1] == '-') {
            a = s[i - 2];
            if (b <= a) ns.push_back('-');
            else if (b - a > 1) {
                xss = "";
                for (char k = static_cast<char>(a + 1); k < b; ++k) {
                    x = static_cast<char>(p1 == 3 ? '*' :
                                          p1 == 1 ? k :
                                          islower(k) ? toupper(k) :
                                          k);
                    xs = string(static_cast<unsigned long>(p2), x);
                    xss += xs;
                }
                if (p3 == 2) reverse(xss.begin(), xss.end());
                ns += xss;
            }
            ns.push_back(b);
        } else if (b != '-' || i == 0 || i == end) {
            ns.push_back(b);
        }
    }
    cout << ns << endl;
    return 0;
}