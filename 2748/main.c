#include <stdio.h>

int main(void) {
    long long fib[91] = {0, 1};
    for (int i = 2; i <= 90; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    scanf("%d", &n);
    printf("%lld\n", fib[n]);
    return 0;
}
