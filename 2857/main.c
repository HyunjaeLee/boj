#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char s[11];
    bool found = false;
    for (int i = 1; i <= 5; i++) {
        scanf("%s", s);
        if (strstr(s, "FBI")) {
            found = true;
            printf("%d ", i);
        }
    }
    if (!found) {
        puts("HE GOT AWAY!");
    }
    return 0;
}
