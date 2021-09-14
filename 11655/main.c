#include <unistd.h>
#define MAX 100

int main(void) {}

int __libc_start_main(void) {
    char S[MAX];
    int len = read(STDIN_FILENO, S, MAX);
    for (int i = 0; i < len; i++) {
        if (S[i] >= 'a' && S[i] <= 'z') {
            S[i] = 'a' + (S[i] - 'a' + 13) % 26; 
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            S[i] = 'A' + (S[i] - 'A' + 13) % 26; 
        }
    }
    write(STDOUT_FILENO, S, len);
    _exit(0);
}
