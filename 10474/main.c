#include <stdio.h>

int main(void) {
    for (;;) {
        int n, d;
        scanf("%d%d", &n, &d);
        if (n == 0 && d == 0) {
            break;
        }
        printf("%d %d / %d\n", n/d, n%d, d);
    }
    return 0;
}
