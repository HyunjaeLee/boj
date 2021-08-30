#include <stdio.h>
#include <math.h>

int main(void) {
    long long factorial[21];
    factorial[0] = 1;
    for (int i = 1; i <= 20; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    double W, L, D;
    double p_tier[5] = {0,};
    scanf("%lf%lf%lf", &W, &L, &D);
    for (int x = 0; x <= 20; x++) {
        for (int y = 0; y <= 20 - x; y++) {
            int z = 20 - x - y;
            int tier = -1;
            int diff = x - y;
            if (diff >= -20 && diff <= -11) {
                tier = 0;
            } else if (diff >= -10 && diff <= -1) {
                tier = 1;
            } else if (diff >= 0 && diff <= 9) {
                tier = 2;
            } else if (diff >= 10 && diff <= 19) {
                tier = 3;
            } else if (diff >= 20) {
                tier = 4;
            }
            p_tier[tier] += factorial[20] * pow(W, x) * pow(L, y) * pow(D, z) / factorial[x] / factorial[y] / factorial[z];
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%.8f\n", p_tier[i]);
    }
    return 0;
}
