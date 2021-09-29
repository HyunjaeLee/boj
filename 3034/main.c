#include <stdio.h>
#include <math.h>

int main(void) {
    int N, W, H;
    scanf("%d%d%d", &N, &W, &H);
    int len = sqrt(W*W + H*H);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        if (a > len) {
            puts("NE");
        } else {
            puts("DA");
        }
    }
    return 0;
}
