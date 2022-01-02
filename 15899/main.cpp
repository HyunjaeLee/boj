#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

struct SegTree {
    int n;
    vector<vector<int>> tree;

    void init(vector<int>& vec, int node, int node_left, int node_right) {
        if (node_left == node_right) {
            tree[node].push_back(vec[node_left]);
            return;
        }
        int mid = (node_left + node_right) / 2;
        init(vec, 2*node, node_left, mid);
        init(vec, 2*node+1, mid+1, node_right);
        merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), back_inserter(tree[node]));
    }

    SegTree(vector<int>& vec) {
        n = vec.size();
        tree.resize(4*n);
        init(vec, 1, 0, n-1);
    }

    int query(int left, int right, int val, int node, int node_left, int node_right) {
        if (node_right < left || right < node_left) return 0;
        if (left <= node_left && node_right <= right) {
            auto& t = tree[node];
            return upper_bound(t.begin(), t.end(), val) - t.begin();
        }
        int mid = (node_left + node_right) / 2;
        return query(left, right, val, 2*node, node_left, mid) + query(left, right, val, 2*node+1, mid+1, node_right);
    }

    int query(int left, int right, int val) {
        return query(left, right, val, 1, 0, n-1);
    }
};

const int VMAX = 200'001, MOD = 1'000'000'007;
int s[VMAX], e[VMAX], cnt = -1;
vector<int> adj[VMAX];

void dfs(int u = 1, int parent = 0) {
    s[u] = ++cnt;
    for (int v : adj[u]) {
        if (v != parent) dfs(v, u);
    }
    e[u] = cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> color(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    vector<int> vec(N);
    for (int i = 1; i <= N; i++) {
        vec[s[i]] = color[i];
    }
    SegTree seg(vec);
    int acc = 0;
    while (M--) {
        int v, c;
        cin >> v >> c;
        acc = (acc + seg.query(s[v], e[v], c)) % MOD;
    }
    cout << acc << '\n';
    return 0;
}
