#include <stdio.h>

void repeat(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
    putchar('\n');
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        repeat((n+1)/2);
        putchar(' ');
        repeat(n/2);
    }
    return 0;
}
