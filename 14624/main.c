#include <stdio.h>

void repeat(char c, int n) {
    for (int i = 0; i < n; i++) {
        putchar(c);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n % 2) {
        repeat('*', n);
        putchar('\n');
        int k = n / 2;
        repeat(' ', k);
        puts("*");
        for (int i = 1; i <= k; i++) {
            repeat(' ', k-i);
            putchar('*');
            repeat(' ', 2*i-1);
            puts("*");
        }
    } else {
        puts("I LOVE CBNU");
    }
    return 0;
}
