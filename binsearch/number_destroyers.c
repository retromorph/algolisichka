#include <stdio.h>
#include <limits.h>

long long arthur(long long a, long long b, long long w, long long x, long long time);
long long alexander(long long c, long long time);

long long arthur(long long a, long long b, long long w, long long x, long long time) {
    b = w - b - 1;
    a -= (b + time * x) / w;
    return a;
}

long long alexander(long long c, long long time) {
    c -= time;
    return c;
}

int main() {
    long long a, b, w, x, c;
    scanf("%lli", &a);
    scanf("%lli", &b);
    scanf("%lli", &w);
    scanf("%lli", &x);
    scanf("%lli", &c);

    long long l = 0, r = LLONG_MAX;

    while (l < r) {
        long long m = l + (r - l) / 2;
        if (arthur(a, b, w, x, m) >= alexander(c, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    printf("%lli\n", l);
}