#include <stdio.h>

int rate_x(int a, int p) {
    return a * p;
}

int rate_y(int b, int c, int d, int p) {
    if (p <= c) {
        return b;
    }
    return b + (p - c) * d;
}

int main(void) {
    int a, b, c, d, p;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &p);
    int x = rate_x(a, p);
    int y = rate_y(b, c, d, p);
    int min = x < y ? x : y;
    printf("%d\n", min);
    return 0;
}
