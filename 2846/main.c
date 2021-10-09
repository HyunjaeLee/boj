#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int max = 0;
    int h;
    scanf("%d", &h);
    int sum = 0;
    for (int i = 0; i < N-1; i++) {
        int prev = h;
        scanf("%d", &h);
        int diff = h - prev;
        sum = diff > 0 ? sum + diff : 0;
        max = sum > max ? sum : max;
    }
    printf("%d\n", max);
    return 0;
}
