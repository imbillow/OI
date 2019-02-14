/*
ID: yaagnto2
LANG: C++14
TASK: transform
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
char square[10][10];
char translated[10][10];

bool array_equals(char a[][10], char b[][10], int n) {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (a[x][y] != b[x][y])
                return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> square[i];
    for (int i = 0; i < n; ++i)
        fin >> translated[i];


    int ans = -1;
    if (array_equals(square, translated, n))
        ans = 6;
    else {
        char tmp[10][10];
        /** 90 degree
         * such:      to:
         *  1, 2, 3     7, 4, 1
         *  4, 5, 6     8, 5, 2
         *  7, 8, 9     9, 6, 3
         *
         *  dst[0][0] = origin[2][0]
         *  dst[0][2] = origin[0][0]
         */
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                tmp[x][y] = square[n - y - 1][x];
        if (array_equals(translated, tmp, n)) {
            ans = 1;
            goto output;
        }

        /** 180 degree
         * such:      to:
         *  1, 2, 3     9, 8, 7
         *  4, 5, 6     6, 5, 4
         *  7, 8, 9     3, 2, 1
         */
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                tmp[x][y] = square[n - x - 1][n - y - 1];
        if (array_equals(translated, tmp, n)) {
            ans = 2;
            goto output;
        }

        /** 270 degree
         * such:      to:
         *  1, 2, 3     3, 6, 9
         *  4, 5, 6     2, 5, 8
         *  7, 8, 9     1, 4, 7
         */
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                tmp[x][y] = square[y][n - x - 1];
        if (array_equals(translated, tmp, n)) {
            ans = 3;
            goto output;
        }

        /** horizontally mirror
         */
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                tmp[x][y] = square[x][n - y - 1];
        if (array_equals(translated, tmp, n)) {
            ans = 4;
            goto output;
        }


        /**
         */
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                tmp[x][y] = square[n - x - 1][y];
        if (array_equals(translated, tmp, n)) {
            ans = 5;
            goto output;
        }

        ans = 7;
    }
    output:
    fout << ans << endl;
    return 0;
}