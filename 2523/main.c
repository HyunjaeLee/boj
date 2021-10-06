#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    for (int i = 1; i < 2 * N; i++) {
        int rep = i < N ? i : 2 * N - i;
        for (int j = 0; j < rep; j++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
