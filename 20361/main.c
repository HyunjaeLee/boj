#include <stdio.h>

int main(void) {
    int n, x, k;
    scanf("%d%d%d", &n, &x, &k);
    int cups[200001] = {0};
    cups[x] = 1;
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        cups[a] = cups[a] ^ cups[b];
        cups[b] = cups[a] ^ cups[b];
        cups[a] = cups[a] ^ cups[b];
    }
    for (int i = 1; i < 200001; i++) {
        if (cups[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}
