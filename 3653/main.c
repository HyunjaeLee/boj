#include <stdio.h>
#include <string.h>

int ft[200001], table[100001];

int sum(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += ft[pos];
        pos &= (pos-1);
    }
    return ret;
}

void add(int pos, int val) {
    while (pos < 200001) {
        ft[pos] += val;
        pos += (pos & -pos);
    }
}

int main(void) {
    int t, n, m, x, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(ft, 0, 200001 * sizeof(int));
        for (int i = n; i > 0; i--) {
            table[i] = n-i+1;
            add(i, 1);
        }
        for (int i = n+1; i <= n+m; i++) {
            scanf("%d", &x);
            r = sum(200000) - sum(table[x]);
            printf("%d ", r);
            add(table[x], -1);
            add(i, 1);
            table[x] = i;
        }
        putchar('\n');
    }
    return 0;
}
