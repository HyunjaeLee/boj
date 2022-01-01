#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct LazySeg {
    vector<ll> tree, lazy;
    int n;

    void init(vector<int>& vec, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) {
            tree[node] = vec[nodeLeft];
            return;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        init(vec, 2*node, nodeLeft, mid);
        init(vec, 2*node+1, mid+1, nodeRight);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    LazySeg(vector<int>& vec) {
        n = vec.size();
        tree.resize(4*n);
        lazy.resize(4*n);
        init(vec, 1, 0, n-1);
    }

    void propagate(int node, int nodeLeft, int nodeRight) {
        if (lazy[node] == 0) return;
        if (nodeLeft < nodeRight) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        tree[node] += lazy[node] * (nodeRight - nodeLeft + 1);
        lazy[node] = 0;
    }

    void update(int left, int right, int val, int node, int nodeLeft, int nodeRight) {
        propagate(node, nodeLeft, nodeRight);
        if (nodeRight < left || right < nodeLeft) return;
        if (left <= nodeLeft && nodeRight <= right) {
            lazy[node] = val;
            propagate(node, nodeLeft, nodeRight);
            return;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        update(left, right, val, 2*node, nodeLeft, mid);
        update(left, right, val, 2*node+1, mid+1, nodeRight);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int left, int right, int val) {
        update(left, right, val, 1, 0, n-1);
    }

    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        propagate(node, nodeLeft, nodeRight);
        if (nodeRight < left || right < nodeLeft) return 0;
        if (left <= nodeLeft && nodeRight <= right) return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, 2*node, nodeLeft, mid) + query(left, right, 2*node+1, mid+1, nodeRight);
    }

    ll query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

const int VMAX = 500001;
vector<int> adj[VMAX];
int s[VMAX], e[VMAX], pay[VMAX];
int no = 0;

void dfs(int u = 1) {
    s[u] = no++;
    for (int v : adj[u]) dfs(v);
    e[u] = no;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M >> pay[1];
    for (int i = 2; i <= N; i++) {
        int parent;
        cin >> pay[i] >> parent;
        adj[parent].push_back(i);
    }
    dfs();
    vector<int> vec(N);
    for (int i = 1; i <= N; i++) {
        vec[s[i]] = pay[i];
    }
    LazySeg seg(vec);
    while (M--) {
        char c;
        int a, x;
        cin >> c >> a;
        if (c == 'p') {
            cin >> x;
            if (s[a]+1 < e[a]) seg.update(s[a]+1, e[a]-1, x);
        } else {
            cout << seg.query(s[a], s[a]) << '\n';
        }
    }
    return 0;
}
