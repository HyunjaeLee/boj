#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // Sieve of Atkin
    int limit = 4000000;
    bool sieve[limit];
    for (int i = 0; i < limit; i++) {
        sieve[i] = false;
    }
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
            int n = 4 * x * x + y * y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
                sieve[n] ^= true;
            }
            n = 3 * x * x + y * y;
            if (n <= limit && n % 12 == 7) {
                sieve[n] ^= true;
            }
            n = 3 * x * x - y * y;
            if (x > y && n <= limit && n % 12 == 11) {
                sieve[n] ^= true;
            }
        }
    }
    for (int r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i < limit; i += r * r) {
                sieve[i] = false;
            }
        }
    }
    int primes[283147] = {2, 3};
    int * p = primes + 2;
    for (int a = 5; a < limit; a++) {
        if (sieve[a]) {
            *p++ = a;
        }
    }
    int N;
    scanf("%d", &N);
    int count = 0;
    int sum = 2;
    int left = 0;
    int right = 1;
    while (left < right && right < 283147) {
        if (sum < N) {
            sum += primes[right++];
        } else if (sum > N) {
            sum -= primes[left++];
        } else {
            count++;
            sum += primes[right++];
            sum -= primes[left++];
        }
    }
    printf("%d\n", count);
}
