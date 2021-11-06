#include <stdio.h>

int main() {
    int n, k;
    scanf("%i", &n);
    scanf("%i", &k);
    int save_k = k;

    int l = 0, r = n;
    while (l < r) {
        int v = l + (r - l) / 2;
        int code_written = v;
        k = save_k;
        while (v/k > 0) {
            code_written += v/k;
            k *= save_k;
        }
        if (code_written < n) {
            l = v + 1;
        } else {
            r = v;
        }
    }
    printf("%i\n", r);
}