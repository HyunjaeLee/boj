#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);
    char s[64];
    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        int last = strlen(s) - 1;
        if (s[last] & 1) {
            puts("odd");
        } else {
            puts("even");
        }
    }
    return 0;
}
