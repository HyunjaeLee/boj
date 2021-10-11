#include <stdio.h>
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))

int N, T[16], P[16];

int solve(int i) {
    if (i > N+1) return -1e9;
    if (i == N+1) return 0;
    return Max(solve(i+1), solve(i+T[i])+P[i]);
}

int main(void) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", T+i, P+i);
    }
    printf("%d\n", solve(1));
    return 0;
}
