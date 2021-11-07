#include "stdio.h"
#include "stdlib.h"

int tryToCut(int *ropes, int n, int k, int length) {
    if (length == 0) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        k -= ropes[i] / length;
        if (k <= 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%i", &n);
    scanf("%i", &k);
    int maxLength = 0;
    int *ropes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%i", &ropes[i]);
        if (ropes[i] > maxLength) {
            maxLength = ropes[i];
        }
    }

    int l = -1;
    int r = maxLength + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (tryToCut(ropes, n, k, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%i", l == -1 ? 0 : l);
}