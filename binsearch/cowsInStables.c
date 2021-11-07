#include "stdio.h"
#include "stdlib.h"

int tryToSet(int *stables, int n, int k, int dist) {
    k -= 1;
    for (int i = 1, prev = stables[0]; i < n; i++) {
        if (stables[i] - prev >= dist) {
            prev = stables[i];
            k--;
        }

        if (k == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%i", &n);
    scanf("%i", &k);
    int *stables = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%i", &stables[i]);
    }

    int l = -1;
    int r = stables[n - 1] - stables[0] + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (tryToSet(stables, n, k, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%i\n", l);
//    int *cows = malloc(k * sizeof(int));
//
//    cows[0] = stables[0];
//    cows[1] = stables[n - 1];
//
//    int dist = 0;
//    for (int i = 0; i < k; i++) {
//        int l = -1, r = n;
//        while (r - l > 1) {
//            int m = l + (r - l) / 2;
//            double p = (stables[l] + stables[r]) / 2.0;
//            if (stables[m] < p) {
//                l = m;
//            } else {
//                r = m;
//            }
//        }
//        cows[2 + i] = r;
//    }
    return 0;
}