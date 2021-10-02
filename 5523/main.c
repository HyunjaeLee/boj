#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int cnt_a = 0;
    int cnt_b = 0;
    for (int i = 0; i < N; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        if (A > B) {
            cnt_a++;
        } else if (A < B) {
            cnt_b++;
        }
    }
    printf("%d %d\n", cnt_a, cnt_b);
    return 0;
}
