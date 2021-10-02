#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if ((n/3 + n%3) % 2) {
        puts("SK");
    } else {
        puts("CY");
    }
    return 0;
}
