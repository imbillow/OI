#include <iostream>

using namespace std;
char characters[26];

int main() {
    int y, x;
    cin >> y >> x;
    for (char i = 0, ch = 'A'; i < 26; ++i, ++ch) characters[i] = ch;

    for (int i = 0; i < y; ++i) {
        for (int j = min(i, x - 1); j > 0; --j) cout << characters[j];
        for (int j = 0; j < max(x - i, 1); ++j) cout << characters[j];
        cout << endl;
    }

    return 0;
}