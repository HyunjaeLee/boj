#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define SET_CAP (1 << 20)
#define ARR_SIZE 1000000
#define WSIZE 10500007
#define TSIZE 6
#define SSIZE 500000

typedef struct Node_t {
    char * name;
    int len;
    struct Node_t * next;
} Node;

typedef struct String_t {
    char * s;
    int len;
} String;

char * rp, * wp, wbuf[WSIZE];
Node arr[ARR_SIZE], * ap, * set[SET_CAP];
String sarr[SSIZE], * sp;

int read_int(void);
void write_int(int n);
void add(char * name, int len);
bool contains(char * name, int len);
bool equals(char * s1, int l1, char * s2, int l2);
unsigned int hash(char * s, int len);
int compare(const void * a, const void * b);

int main(void) {
    char * input, * name;
    struct stat sb;
    int N, M, i, len, size;
    fstat(0, &sb);
    input = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, 0, 0);
    rp = input;
    wp = wbuf;
    ap = arr;
    sp = sarr;
    N = read_int();
    M = read_int();
    for (i = 0; i < N; i++) {
        name = rp;
        len = 0;
        while (*rp++ != '\n') len++;
        add(name, len);
    }
    for (i = 0; i < M; i++) {
        name = rp;
        len = 0;
        while (*rp++ != '\n') len++;
        if (contains(name, len)) {
            String * str = sp++;
            str->s = name;
            str->len = len;
        }
    }
    size = sp - sarr;
    if (size) {
        write_int(size);
        qsort(sarr, size, sizeof(String), compare);
        for (i = 0; i < size; i++) {
            memcpy(wp, sarr[i].s, sarr[i].len);
            wp += sarr[i].len;
            *wp++ = '\n';
        }
        write(1, wbuf, wp - wbuf);
    } else {
        puts("0");
    }
    munmap(input, sb.st_size);
    return 0;
}

int read_int(void) {
    register int n = 0;
    char c;
    while ((c = *rp++) >= '0') {
        n = (n << 3) + (n << 1) + (c & 0xF);
    }
    write(1, wbuf, wp - wbuf);
    return n;
}

void write_int(int n) {
    char * tp, tbuf[TSIZE];
    tp = tbuf;
    for (;;tp++) {
        *tp = (char)(n % 10 | '0');
        n /= 10;
        if (!n) break;
    }
    for (;;tp--) {
        *wp++ = *tp;
        if (tp == tbuf) break;
    }
    *wp++ = '\n';
}

void add(char * name, int len) {
    unsigned int pos = hash(name, len) & 0xFFFFF;
    Node * node = ap++;
    node->name = name;
    node->len = len;
    node->next = set[pos];
    set[pos] = node;
}

bool contains(char * name, int len) {
    unsigned int pos = hash(name, len) & 0xFFFFF;
    Node * node = set[pos];
    while (node) {
        if (equals(node->name, node->len, name, len)) {
            return true;
        }
        node = node->next;
    }
    return false;
}

bool equals(char * s1, int l1, char * s2, int l2) {
    if (l1 != l2) return false;
    for (int i = 0; i < l1; i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

unsigned int hash(char * s, int len) {
    unsigned int h = 0;
    for (int i = 0; i < len; i++) {
        h = h * 31 + s[i];
    }
    return h;
}

int compare(const void * a, const void * b) {
    int min, res, i;
    String * str1, * str2;
    str1 = (String *)a;
    str2 = (String *)b;
    if (str1->len < str2->len) {
        min = str1->len;
        res = -1;
    } else if (str1->len > str2->len) {
        min = str2->len;
        res = 1;
    } else {
        min = str1->len;
        res = 0;
    }
    for (i = 0; i < min; i++) {
        if (str1->s[i] != str2->s[i]) {
            res = str1->s[i] - str2->s[i];
            break;
        }
    }
    return res;
}
