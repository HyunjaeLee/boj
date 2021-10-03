#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t); 
    for (int i = 0; i < t; i++) {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        printf("$%.2f\n", 350.34*a + 230.90*b + 190.55*c + 125.30*d + 180.90*e);
    }
    return 0;
}
