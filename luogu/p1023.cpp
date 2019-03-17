#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
int expect_x, expect_y, dy;
int D[100001][2];

int main() {
    cin >> expect_x;
    int x, y, i{}, tx, td;
    while (cin >> x >> y && x != -1 && y != -1) {
        i++;
        if (i > 1 && x - D[i - 1][0] > 1) {
            tx = D[i - 1][0];
            td = (y - D[i - 1][1]) / (x - tx);
            for (int k = tx + 1; k < x; ++k, ++i) {
                D[i][0] = k;
                D[i][1] = D[i - 1][1] + td;
            }
        }
        D[i][0] = x;
        D[i][1] = y;
    }
    cin >> dy;
    x = D[i][0];
    y = D[i][1];
    while (y > 0) {
        ++i;
        x += 1;
        y -= dy;
        D[i][0] = x;
        D[i][1] = y;
    }

    for (int j = 1; j < i; ++j) {
        if (D[j][0] == expect_x)expect_y = D[j][1];
    }
    bool is{};
    int a, b;
    int bx = D[1][0];
    for (int k = 0; k <= expect_x; ++k) {
        for (int o : {k, -k}) {
            is = true;
            a = (o + expect_x - bx) * expect_y;
            for (int z = 1; z < i; ++z) {
                b = (o + D[z][0] - bx) * D[z][1];
                if (a < b) {
                    is = false;
                    break;
                }
            }
            if (is) {
                cout << o << endl;
                return 0;
            }
        }
    }
    cout << "NO SOLUTION" << endl;
    return 0;
}