#include <stdio.h>

int main(void) {
    double prev;
    scanf("%lf", &prev);
    for (;;) {
        double cur;
        scanf("%lf", &cur);
        if (cur == 999) {
            break;
        }
        printf("%.2f\n", cur-prev);
        prev = cur;
    }
    return 0;
}
