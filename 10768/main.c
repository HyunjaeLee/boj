#include <stdio.h>

int main(void) {
    int month, day;
    scanf("%d%d", &month, &day);
    if (month < 2) {
        puts("Before");
    } else if (month > 2) {
        puts("After");
    } else if (day < 18) {
        puts("Before");
    } else if (day > 18) {
        puts("After");
    } else {
        puts("Special");
    }
    return 0;
}
