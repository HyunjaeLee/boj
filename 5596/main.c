#include <stdio.h>

void sum(int * p) {
    for (int i = 0; i < 4; i++) {
        int score;
        scanf("%d", &score);
        *p += score;
    }
}

int main(void) {
    int s = 0;
    int t = 0;
    sum(&s);
    sum(&t);
    printf("%d\n", s > t ? s : t);
    return 0;
}
