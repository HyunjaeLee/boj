#include <stdio.h>
#include <math.h>

int main(void) {
    for (int i = 1;;i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        printf("Triangle #%d\n", i);
        if (a == -1) {
            if (c > b) {
                printf("a = %.3f\n", sqrt(c*c-b*b));
            } else {
                puts("Impossible.");
            }
        } else if (b == -1) {
            if (c > a) {
                printf("b = %.3f\n", sqrt(c*c-a*a));
            } else {
                puts("Impossible.");
            }
        } else if (c == -1) {
            printf("c = %.3f\n", sqrt(a*a+b*b));
        }
        putchar('\n');
    }
    return 0;
}
