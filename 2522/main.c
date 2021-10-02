#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 2*n; i++) {
        int x = abs(n - i);
        for (int j = 0; j < x; j++) {
            putchar(' ');
        }
        for (int j = 0; j < n-x; j++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
