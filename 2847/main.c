#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    int result = 0;
    for (int i = n-1; i > 0; i--) {
        if (a[i-1] < a[i]) {
            continue;
        }
        result += a[i-1] - a[i] + 1;
        a[i-1] = a[i] - 1;
    }
    printf("%d\n", result);
}
