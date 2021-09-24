#include <unistd.h>
#define RSIZE 33
#define WSIZE 10

char rbuf[RSIZE];
char wbuf[WSIZE];
char *rp = rbuf;
char *wp = wbuf;

int read_int(void);
void write_int(int);

int main(void) {}

int __libc_start_main(void) {
    read(STDIN_FILENO, rbuf, RSIZE);
    int A = read_int();
    int B = read_int();
    int C = read_int();
    write_int((C&1) ? (A^B) : A);
    write(STDOUT_FILENO, wbuf, wp-wbuf);
    _exit(0);
}

int read_int(void) {
    int n = 0;
    char c;
    while ((c = *rp++) >= '0') {
        n = (n<<1) + (n<<3) + (c&0xF);
    }
    return n;
}

void write_int(int n) {
    char tbuf[WSIZE];
    char *tp = tbuf;
    for(;;tp++) {
        *tp = n%10 | '0';
        n /= 10;
        if (!n) break;
    }
    for (;;tp--) {
        *wp++ = *tp;
        if (tp == tbuf) break;
    }
}
