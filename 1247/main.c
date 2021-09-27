#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <unistd.h>

char * p;

int parse32(void);
__int128 parse128(void);

int main(void) {
    char * data;
    struct stat st;
    fstat(0, &st);
    data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
    p = data;
    char buf[6];
    char * wp = buf;
    for (int i = 0; i < 3; i++) {
        __int128 S = 0;
        int N = parse32();
        for (int j = 0; j < N; j++) {
            S += parse128();
        }
        if (S > 0) {
            *wp++ = '+';
        } else if (S < 0) {
            *wp++ = '-';
        } else {
            *wp++ = '0';
        }
        *wp++ = '\n';
    }
    write(1, buf, 6);
    munmap(data, st.st_size);
    return 0;
}

int parse32(void) {
    int n = 0;
    char c;
    while ((c=*p++) >= '0') {
        n = (n<<1) + (n<<3) + (c&0xF);
    }
    return n;
}

__int128 parse128(void) {
    bool negative = false;
    if (*p == '-') {
        p++;
        negative = true;
    }
    __int128 n = 0;
    char c;
    while ((c=*p++) >= '0') {
        n = (n<<1) + (n<<3) + (c&0xF);
    }
    if (negative) {
        n = -n;
    }
    return n;
}
