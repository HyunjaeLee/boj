#include <stdio.h>

int main(void) {
    int n0;
    for (int i = 1; scanf("%d", &n0) && n0 > 0; i++) {
        int n4 = (3*n0 + 1) / 2 / 3;
        printf("%d. %s %d\n", i, (n0%2 ? "odd" : "even"), n4);
    }
    return 0;
}
