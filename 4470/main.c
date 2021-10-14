#include <stdio.h>
#define SIZE 64

int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    char s[SIZE];
    for (int i = 1; i <= N; i++) {
        fgets(s, SIZE, stdin);
        printf("%d. %s", i, s);
    }
    return 0;
}
