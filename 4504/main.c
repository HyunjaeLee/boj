#include <stdio.h>

int main(void) {
    int n, x;
    scanf("%d%d", &n, &x);
    while (x) {
        if (x % n) {
            printf("%d is NOT a multiple of %d.\n", x, n);
        } else {
            printf("%d is a multiple of %d.\n", x, n);
        }
        scanf("%d", &x);
    }
    return 0;
}
