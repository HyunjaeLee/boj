#include <stdio.h>
#include <math.h>

int main(void) {
    double pi = acos(-1);
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    double x = (double)C / A;
    int n = x / pi;
    double left, right;
    if (n % 2) {
        left = x;
        right = (n + 1) * pi;
    } else {
        left = n * pi;
        right = x;
    }
    double mid = (left + right) / 2;
    for (int i = 0; i < 64; i++) {
        if (A * mid + B * sin(mid) - C < 0) {
            left = mid;
        } else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    printf("%.16f\n", mid);
    return 0;
}

