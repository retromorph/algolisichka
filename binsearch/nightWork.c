#include "stdio.h"

// https://codeforces.com/problemset/problem/165/B

int codeLines(int v, int k) {
    int result = 0;
    while (v > 0) {
        result += v;
        v = v / k;
    }
    return result;
}

int main() {
    int n, k;
    scanf("%i", &n);
    scanf("%i", &k);

    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
//        printf("%i %i\n", m,  codeLines(m, k));
        if (codeLines(m, k) < n) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%i\n", r);
    return 0;
}