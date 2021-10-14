#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

bool right(ll a, ll b, ll c) {
    if (a*a + b*b == c*c) {
        return true;
    }
    if (a*a + c*c == b*b) {
        return true;
    }
    if (b*b + c*c == a*a) {
        return true;
    }
    return false;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Scenario #%d:\n", i);
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        puts(right(a, b, c) ? "yes\n" : "no\n");
    }
    return 0;
}
