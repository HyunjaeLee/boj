#include <stdio.h>

typedef long long ll;

int main(void) {
    ll S, X;
    scanf("%lld %lld", &S, &X);
    ll ans = 0;
    ll diff = S - X;
    ll ext = diff >> 1;
    if (diff >= 0 && !(diff & 1) && !(ext & X)) {
        int cnt = 0;
        for (int i = 0; i < 40; i++) {
            if (X & (1LL << i)) cnt++;
        }
        ans = (1LL << cnt) - (ext ? 0 : 2);
    }
    printf("%lld\n", ans);
    return 0;
}
