#include <stdio.h>
#include <stdbool.h>
#define SIZE (1<<17)
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int min_tree[SIZE*2], max_tree[SIZE*2];

void init() {
    for (int i = 0; i < SIZE; i++) {
        min_tree[SIZE+i] = i;
        max_tree[SIZE+i] = i;
    }
    for (int i = SIZE-1; i > 0; i--) {
        min_tree[i] = MIN(min_tree[i*2], min_tree[i*2+1]);
        max_tree[i] = MAX(max_tree[i*2], max_tree[i*2+1]);
    }
}

int min_query(int left, int right, int node, int node_left, int node_right) {
    if (node_right < left || right < node_left) {
        return 1e9;
    }
    if (left <= node_left && node_right <= right) {
        return min_tree[node];
    }
    int mid = (node_left + node_right) / 2;
    int lres = min_query(left, right, 2*node, node_left, mid);
    int rres = min_query(left, right, 2*node+1, mid+1, node_right);
    return MIN(lres, rres);
}

int max_query(int left, int right, int node, int node_left, int node_right) {
    if (node_right < left || right < node_left) {
        return -1;
    }
    if (left <= node_left && node_right <= right) {
        return max_tree[node];
    }
    int mid = (node_left + node_right) / 2;
    int lres = max_query(left, right, 2*node, node_left, mid);
    int rres = max_query(left, right, 2*node+1, mid+1, node_right);
    return MAX(lres, rres);
}

bool query(int left, int right) {
    int min = min_query(left, right, 1, 0, SIZE-1);
    int max = max_query(left, right, 1, 0, SIZE-1);
    return left == min && right == max;
}

void update(int i, int val) {
    i += SIZE;
    min_tree[i] = val;
    max_tree[i] = val;
    while (i > 0) {
        i /= 2;
        min_tree[i] = MIN(min_tree[i*2], min_tree[i*2+1]);
        max_tree[i] = MAX(max_tree[i*2], max_tree[i*2+1]);
    }
}

void swap(int a, int b) {
    if (a == b) {
        return;
    }
    int tmp = min_tree[SIZE+a];
    update(a, min_tree[SIZE+b]);
    update(b, tmp);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        int N, K;
        scanf("%d%d", &N, &K);
        while (K--) {
            int Q, A, B;
            scanf("%d%d%d", &Q, &A, &B);
            if (Q) {
                puts(query(A, B) ? "YES" : "NO");
            } else {
                swap(A, B);
            }
        }
    }
    return 0;
}
