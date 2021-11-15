#include <stdio.h>
#define SIZE 1000001

int ft[SIZE];

int sum(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += ft[pos];
        pos &= (pos-1);
    }
    return ret;
}

void add(int pos, int val) {
    while (pos < SIZE) {
        ft[pos] += val;
        pos += (pos & -pos);
    }
}

int search(int ord) {
    int res, mid;
    int lo = 1, hi = 1000000;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        res = sum(mid);
        if (res < ord) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return hi;
}

int main(void) {
    int n, a, b, c, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        switch (a) {
        case 1:
            x = search(b);
            printf("%d\n", x);
            add(x, -1);
            break;
        case 2:
            scanf("%d", &c);
            add(b, c);
            break;
        }
    }
    return 0;
}
