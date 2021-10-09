#include <stdio.h>

int main(void) {
    char s[101];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] ^= 32;
    }
    printf("%s\n", s);
}
