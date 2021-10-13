#include <stdio.h>

void print_grade(int k) {
    if (k >= 97 && k <= 100) {
        puts("A+");
    } else if (k >= 90 && k <= 96) {
        puts("A");
    } else if (k >= 87 && k <= 89) {
        puts("B+");
    } else if (k >= 80 && k <= 86) {
        puts("B");
    } else if (k >= 77 && k <= 79) {
        puts("C+");
    } else if (k >= 70 && k <= 76) {
        puts("C");
    } else if (k >= 67 && k <= 69) {
        puts("D+");
    } else if (k >= 60 && k <= 66) {
        puts("D");
    } else if (k >= 0 && k <= 59) {
        puts("F");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    char a[10];
    int b;
    for (int i = 0; i < n; i++) {
        scanf("%s%d", a, &b);
        printf("%s ", a);
        print_grade(b);
    }
    return 0;
}
