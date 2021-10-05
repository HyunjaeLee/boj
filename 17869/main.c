#include <stdio.h>

int main(void) {
    long long n;
    scanf("%lld", &n);
    int count = 0;
    while (n != 1) {
        n = n%2 ? n+1 : n/2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}
