#include "stdio.h"
#include "limits.h"

// https://codeforces.com/problemset/problem/382/B

long long alex(long long c, long long t) {
    return c - t;
}

long long artur(long long a, long long b, long long w, long long x, long long t) {
    b = w - b - 1;
    return a - ((b + t * x) / w);
}

int main() {
    long long a, b, w, x, c;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &w);
    scanf("%lld", &x);
    scanf("%lld", &c);

    long long l = -1;
    long long r = 9223372036854775807 - 1;
    while (r - l > 1) {
        long long m = l + (r - l) / 2;
        if (artur(a, b, w, x, m) < alex(c, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%lld", r);
    return 0;
}