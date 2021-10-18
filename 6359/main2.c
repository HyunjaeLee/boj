#include <stdio.h>
#include <math.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int result = sqrt(n);
        printf("%d\n", result);
    }
}
