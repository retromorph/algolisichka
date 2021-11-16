#include <stdio.h>

#define MAX_LENGTH 100000

int main() {
    int N, K; 
    int coordinates[MAX_LENGTH];
    scanf("%i", &N); /* N - стойла */
    scanf("%i", &K); /* K - коровы */

    for (register int i = 0; i < N; i++) {
        scanf("%i", &coordinates[i]);
    }

    int l = 0, r = coordinates[N-1] - coordinates[0] + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        int cows_remained = K - 1; /* Первая корова всегда в первом стойле */
        register int left_stall = 0, right_stall = 0; /* Номера левого и правого стойла */

        while (cows_remained > 0) {
            for (right_stall = left_stall + 1; right_stall < N; right_stall++) {
                if (coordinates[right_stall] - coordinates[left_stall] >= m) {
                    left_stall = right_stall;
                    cows_remained--;
                    break;
                }
            }
            if (right_stall == N) {
                break;
            }
        }

        if (cows_remained > 0) {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%i\n", l);
}