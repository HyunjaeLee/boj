#include <stdio.h>
typedef long long ll;

int main(void) {
    ll x1, y1, r1, x2, y2, r2;
    scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &r1, &x2, &y2, &r2);
    if ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) < (r1+r2)*(r1+r2)) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
