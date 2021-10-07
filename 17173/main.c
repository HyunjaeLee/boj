#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d%d", &N, &M);
    int s[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &s[i]);
    }
    int sum = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % s[j] == 0) {
                sum += i;
                break;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
