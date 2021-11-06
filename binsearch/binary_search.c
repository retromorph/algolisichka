/* O(K*logN) */

#include <stdio.h>

#define MAX_LENGTH 100000

int main() {
    int N, K;
    int arr1[MAX_LENGTH], arr2[MAX_LENGTH];
    scanf("%i", &N);
    scanf("%i", &K);

    for (register int i = 0; i < N; i++) {
        scanf("%i", &arr1[i]);
    }

    for (register int i = 0; i < K; i++) {
        scanf("%i", &arr2[i]);
        
        int l = 0, r = N;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr1[m] < arr2[i]) {
                l = m + 1;
            } else if (arr1[m] > arr2[i]) {
                r = m;
            } else {
                printf("YES\n");
                break;
            }
        }
        if (l >= r) printf("NO\n");
    }
}