#include <stdio.h>

void repeat(char c, int r) {
    for (int i = 0; i < r; i++) {
        putchar(c);
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    repeat(' ', N-1);
    puts("*");
    for (int i = 0; i < N-1; i++) {
        repeat(' ', N-i-2);
        putchar('*');
        repeat(' ', 2*i+1);
        puts("*");
    }
    return 0;
}
