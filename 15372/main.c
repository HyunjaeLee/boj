#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        long long N;
        scanf("%lld", &N);
        printf("%lld\n", N*N);
    }
    return 0;
}
