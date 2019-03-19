#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <climits>

using namespace std;
int a[500001];
int sorted_a[500001];
long long t = 0;

void fast_scan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())number = number * 10 + c - 48;
    if (negative) number *= -1;
}

void dsort(int arr[], int l, int o[]) {
    if (l < 2) {
        o[0] = arr[0];
        return;
    }
    int mid = l / 2;
    int rl = l - mid;
    int *out = new int[l + 2];
    out[mid] = out[l + 1] = INT_MAX;

    dsort(arr, mid, out);
    dsort(arr + mid, rl, out + mid + 1);

    for (int k = 0, i = 0, j = mid + 1; k < l; ++k) {
        if (out[i] <= out[j]) {
            o[k] = out[i];
            ++i;
        } else {
            t += j - k - 1;
            o[k] = out[j];
            ++j;
        }
    }
    delete[](out);
}

int main() {
    int n;
    fast_scan(n);
    for (int i = 0; i < n; ++i) fast_scan(a[i]);
    dsort(a, n, sorted_a);
    cout << t << endl;
    return 0;
}