#include <stdio.h>
#include <string.h>

int main(void) {
    char s[10001];
    fgets(s, 10001, stdin);
    int len = strlen(s);
    int joi = 0;
    for (int i = 0; i < len-2; i++) {
        if (s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I') {
            joi++;
        }
    }
    int ioi = 0;
    for (int i = 0; i < len-2; i++) {
        if (s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') {
            ioi++;
        }
    }
    printf("%d\n%d\n", joi, ioi);
    return 0;
}
