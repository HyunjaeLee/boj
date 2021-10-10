#include <unistd.h>
#define SIZE 1000001

int main(void) {}

int __libc_start_main(void) {
    char s[SIZE];
    ssize_t len = read(STDIN_FILENO, s, SIZE);
    for (int i = 0; s[i] > 30; i++) {
        s[i] ^= 32;
    }
    write(STDOUT_FILENO, s, len);
    _exit(0);
}
