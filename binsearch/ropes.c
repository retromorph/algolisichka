#include <stdio.h>

#define MAX_ARRAY_LENGTH 10000

int main() {
    int N, K; 
    int rope_length[MAX_ARRAY_LENGTH];
    int l = 0, r = 0;
    scanf("%i", &N); /* N - веревочки */
    scanf("%i", &K); /* K - дома */

    for (register int i = 0; i < N; i++) {
        scanf("%i", &rope_length[i]);
        if (rope_length[i] > r) {
            r = rope_length[i] + 1;
        }
    }

    while (r - l > 1) {
        int m = l + (r - l) / 2;
        int houses_remained = K;

        for (register int i = 0; i < N; i++) {
            int current_rope = rope_length[i];
            int sum_length = 0;
            while (current_rope >= m) {
                sum_length += m;
                current_rope -= m;
                houses_remained--;
            }
            if (sum_length == m*K) {
                break;
            }
        }

        if (houses_remained > 0) {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%i\n", l);
}