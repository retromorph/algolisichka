#include "stdio.h"

// https://codeforces.com/problemset/problem/750/A

int main() {
    int n, k;
    scanf("%i", &n);
    scanf("%i", &k);
    int t = 4 * 60 - k;

    int l = 0;
    int r = n;
    int res = 0;
    while (l < r) {
        int m = l + (r - l) / 2;
        int sm = (5 * (m + 1) * (m + 2)) / 2;
        if (sm <= t) {
            l = m + 1;
            res = m + 1;
        } else if (sm > t) {
            r = m;
        }
    }

    printf("%i\n", res);
    return 0;
}