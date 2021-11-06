#include "stdio.h"

// https://codeforces.com/problemset/problem/1566/A
int main() {
    int N;
    scanf("%i", &N);
    for (int i = 0; i < N; i++) {
        long n, s;
        scanf("%li", &n);
        scanf("%li", &s);
        long res = s / ((n / 2) + 1);
        printf("%li\n", res);
    }
    return 0;
}