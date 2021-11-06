#include <stdio.h>
#include <stdlib.h>

int reclinsearch(int *arr, int l, int r, int toFind) {
    if (arr[l] == toFind) {
        return l;
    }
    if (l == r) {
        return -1;
    }
    return reclinsearch(arr, l + 1, r, toFind);
}

size_t factorialCacheSize = 0;
int *factorialCache = NULL;

int factorial(int n) {
    // инициализация массива кэша, если он не инициализирован, либо увеличение размера массива кэша, если n больше размера массива
    if (factorialCacheSize < n) {
        int *factorialCacheTmp = malloc(sizeof(int) * n);

        if (factorialCacheSize != 0) {
            // если это не первичная инициализация, то скопировать старую информацию в новый массив
            for (size_t i = 0; i < factorialCacheSize; i++) {
                factorialCacheTmp = factorialCache[i];
            }
            // освободить место из-под старого массива
            free(factorialCache);
        } else {
            // если это первичная инициализация, то поставить факториал от нуля еденицей
            factorialCacheTmp[0] = 1;
        }
        factorialCache = factorialCacheTmp;
        factorialCacheSize = n;
    }

    if (factorialCache[n] == 0) {
        // если кэша факториала для n не существует, то создать его рекурсивно
        factorialCache[n] = n * factorial(n - 1);
    }
    return factorialCache[n];
}

int main() {
    int n;
    scanf("%i", &n);
    printf("%i", factorial(n));
    return 0;
}
