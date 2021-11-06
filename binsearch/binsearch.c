#include "stdio.h"

size_t binsearch(int *arr, int l, int r, int toFind) {
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] < toFind) {
            l = m + 1;
        } else if (arr[m] > toFind) {
            r = m;
        } else {
            return m;
        }
    }
    return -1;
}

size_t recbinsearch(int *arr, int l, int r, int toFind) {
    if (l >= r) {
        return -1;
    }
    // т. к. вариант (l + r)/2 не сбалансирован из-за того, что у нас интервал [l, r). Этот способ может выдать m = r, но r не включено в [l, r)
    int m = l + (r - l) / 2;

    if (arr[m] < toFind) {
        return recbinsearch(arr, m + 1, r, toFind);
    } else if (arr[m] > toFind) {
        return recbinsearch(arr, l, m, toFind);
    }
    return m;
}

int main() {

    return 0;
}