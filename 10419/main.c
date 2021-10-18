#include <stdio.h>
#include <math.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int d;
        scanf("%d", &d);
        int result = (sqrt(1+4*d)-1)/2;
        printf("%d\n", result);
    }
    return 0;
}
