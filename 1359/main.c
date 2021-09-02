#include <stdio.h>

int combination(int n, int r) {
    if (n < r) return 0;
    if (n - r < r) return combination(n, n - r);
    if (r == 0) return 1;
    int denominator = 1;
    int numerator = 1;
    for (int i = 0; i < r; i++) {
        denominator *= n - i;
        numerator *= r - i;
    }
    return denominator / numerator;
}

int main(void) {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    int numerator = 0;
    int denominator = combination(N, M);
    for (int i = 0; i <= M - K; i++) {
        numerator += combination(M, K+i) * combination(N-M, M-K-i);
    }
    printf("%.9f\n", (double)numerator/denominator);
    return 0;
}
