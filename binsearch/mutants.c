#include <stdio.h>

#define MAX_LENGTH 100000

int countLeftBinsearch(int *array, int l, int r, int toCount) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (array[m] < toCount) {
            l = m;
        } else {
            r = m;
        }
    }
    return (l >= r) ? 0 : r;
}

int countRightBinsearch(int *array, int l, int r, int toCount) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (array[m] <= toCount) {
            l = m;
        } else {
            r = m;
        }
    }
    return (l >= r) ? 0 : (l + 1);
}

int main() {
    int N, M;
    int array_mutants[MAX_LENGTH], array_requests[MAX_LENGTH];
    
    scanf("%i", &N);
    for (register int i = 0; i < N; i++) {
        scanf("%i", &array_mutants[i]);
    }

    scanf("%i", &M);
    for (register int i = 0; i < M; i++) {
        scanf("%i", &array_requests[i]);
        int result = countRightBinsearch(array_mutants, -1, N, array_requests[i]) - countLeftBinsearch(array_mutants, -1, N, array_requests[i]);
        printf("%i\n", result);
    }    
}