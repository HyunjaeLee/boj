#pragma GCC optimize("O3")
#pragma GCC target("arch=haswell")
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#define DICT_CAP (1 << 18)
#define LIST_SIZE 100001
#define W_SIZE 2100000

typedef struct Element {
    int idx;
    char * name;
    int len;
    struct Element * next;
} Element;

int read_uint(void);
unsigned int hash(const char *, int);
void add(Element * elem);
Element * get(const char *, int);
bool equal(const char *, const char *, int, int);
void write_uint(int);

Element * dict[DICT_CAP], list[LIST_SIZE];
char * rp, w_buf[W_SIZE], * wp = w_buf;

int main(void) {
    char * mem;
    struct stat st;
    fstat(0, &st);
    mem = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
    rp = mem;
    int N = read_uint();
    int M = read_uint();
    for (int i = 1; i <= N; i++) {
        list[i].idx = i;
        list[i].name = rp;
        while (*rp++ != '\n');
        list[i].len = (int)(rp - 1 - list[i].name);
        list[i].next = NULL;
        add(&list[i]);
    }
    for (int i = 0; i < M; i++) {
        if (*rp <= '9') {
            int idx = read_uint();
            memcpy(wp, list[idx].name, list[idx].len);
            *(wp + list[idx].len) = '\n';
            wp += list[idx].len + 1;
        } else {
            char * s = rp;
            while (*rp++ != '\n');
            int len = (int)(rp - 1 - s);
            Element * elem = get(s, len);
            write_uint(elem->idx);
        }
    }
    write(1, w_buf, wp - w_buf);
    munmap(mem, st.st_size);
    return 0;
}

void write_uint(register int x) {
    char buf[6];
    char * p = buf;
    for (;;p++) {
        *p = (char)(x % 10 | '0');
        x /= 10;
        if (!x) break;
    }
    for (;;p--) {
        *wp++ = *p;
        if (p == buf) break;
    }
    *wp++ = '\n';
}

void add(Element * elem) {
    unsigned int pos = hash(elem->name, elem->len) & 0x3FFFF;
    if (dict[pos] != NULL) {
        elem->next = dict[pos];
    }
    dict[pos] = elem;
}

Element * get(const char * s, int len) {
    unsigned int pos = hash(s, len) & 0x3FFFF;
    Element * elem = dict[pos];
    while (elem->next != NULL) {
        if (equal(s, elem->name, len, elem->len)) return elem;
        elem = elem->next;
    }
    return elem;
}

bool equal(const char * s1, const char * s2, int len1, int len2) {
    if (len1 != len2) return false;
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

unsigned int hash(const char * s, int len) {
    register unsigned int h = 0;
    for (int i = 0; i < len; i++) {
        h = h * 31 + s[i];
    }
    return h;
}

int read_uint(void) {
    int n = 0;
    char c;
    while ((c = *rp++) >= '0') {
        n = (n << 1) + (n << 3) + (c & 0xF);
    }
    return n;
}
