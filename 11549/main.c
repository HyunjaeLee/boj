#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    int count = 0;
    for (int i = 0; i < 5; i++) {
        int x;
        scanf("%d", &x);
        if (x == t) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
