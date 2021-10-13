#include <stdio.h>

int main(void) {
    int winner = 0;
    int max = 0;
    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int score;
            scanf("%d", &score);
            sum += score;
        }
        if (sum > max) {
            winner = i;
            max = sum;
        }
    }
    printf("%d %d\n", winner, max);
    return 0;
}
