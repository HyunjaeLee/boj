#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if ((n/3 + n%3) % 2) {
        puts("CY");
    } else {
        puts("SK");
    }
    return 0;
}
