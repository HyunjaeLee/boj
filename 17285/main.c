#include <unistd.h>
#define SIZE 101

int main(void) {}

int __libc_start_main(void) {
    char buf[SIZE];
    char * p = buf;
    read(STDIN_FILENO, buf, SIZE);
    char key = (buf[0] ^ 'C');
    while (*p != '\n' && *p != 0) {
        *p++ ^= key;
    }
    write(STDOUT_FILENO, buf, p - buf);
    _exit(0);
}
