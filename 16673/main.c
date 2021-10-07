#include <stdio.h>

int main(void) {
    int c, k, p;
    scanf("%d%d%d", &c, &k, &p);
    printf("%d\n", k*c*(c+1)/2+p*c*(c+1)*(2*c+1)/6);
    return 0;
}
