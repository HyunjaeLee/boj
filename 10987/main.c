#include <stdio.h>

int main(void) {
    char s[102];
    fgets(s, 102, stdin);
    char * p = s;
    int count = 0;
    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            count++;
        }
        p++;
    }
    printf("%d\n", count);
    return 0;
}
