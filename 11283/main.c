#include <unistd.h>

char buf[5];
char * p;

void write_int(int n) {
    char tbuf[5];
    char * tp = tbuf;
    for (;;tp++) {
        *tp = (char)(n % 10 | '0');
        n /= 10;
        if (!n) break;
    }
    for (;;tp--) {
        *p++ = *tp;
        if (tp == tbuf) break;
    }
}

int main(void) {}

int __libc_start_main(void) {
    p = buf;
    char s[3];
    read(0, s, 3);
    int code = ((s[0] & 0xF) << 12) | ((s[1] & 0x3F) << 6) | (s[2] & 0x3F);
    write_int(code - 44031);
    write(1, buf, p - buf);
    _exit(0);
}
