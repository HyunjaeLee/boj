#include <unistd.h>

int main(void) {}

int __libc_start_main(void) {
    int p[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};
    char r[5];
    read(0, r, 5);
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += p[r[i] & 0xF];
    }
    char w[6];
    char t[6];
    char *wp = w;
    char * tp = t;
    for (;;tp++) {
        *tp = sum % 10 | '0';
        sum /= 10;
        if (!sum) break;
    }
    for (;;tp--) {
        *wp++ = *tp;
        if (tp == t) break;
    }
    write(1, w, wp - w);
    _exit(0);
}
