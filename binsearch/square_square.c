#include <stdio.h>
#include <tgmath.h>

#define EPS 0.000001

int main() {
    double C, x, y;
    scanf("%lf", &C);

    double l = 0, r = C;
    x = l + (r - l) / 2;
    y = sqrt(x) + x * x;
    while (fabs(y - C) > EPS) {
        x = l + (r - l) / 2;
        y = sqrt(x) + x * x;
        if (y < C) {
            l = x;
        } else {
            r = x;
        }
    }
    printf("%.9lf\n", x);
}