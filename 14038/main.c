#include <stdio.h>

int main(void) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        char c = getchar();
        getchar();
        if (c == 'W') cnt++;
    }
    printf("%d\n", cnt ? 3-(cnt-1)/2 : -1);
}
