#include <stdio.h>

int rooms[101];

int solve(int n) {
    for (int i = 1; i <= n; i++) {
        rooms[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j < 101; j++) {
            rooms[i*j] ^= 1;
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (rooms[i]) result++;
    }
    return result;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}
