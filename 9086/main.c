#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(void) {
    int T;
    scanf("%d", &T);
    char s[SIZE];
    for (int i = 0; i < T; i++) {
        scanf("%s", s);
        printf("%c%c\n", s[0], s[strlen(s)-1]);
    }
    return 0;
}
