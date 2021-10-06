#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    char s[21];
    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] += 32;
            }
        }
        puts(s);
    }
    return 0;
}
