#include <unistd.h>

int main(void) {}

int __libc_start_main(void) {
    char buf[64];
    ssize_t len = read(STDIN_FILENO, buf, 64);
    if (buf[len - 1] == '\n') {
        len--;
    }
    buf[len] = '?';
    buf[len + 1] = '?';
    buf[len + 2] = '!';
    write(STDOUT_FILENO, buf, len + 3);
    _exit(0);
}
