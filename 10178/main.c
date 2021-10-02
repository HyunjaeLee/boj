#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int c, v;
        scanf("%d%d", &c, &v);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", c/v, c%v);
    }
    return 0;
}
