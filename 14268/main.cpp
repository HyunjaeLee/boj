#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100'002;
vector<int> adj[MAX];
int s[MAX], e[MAX], bit[MAX], cnt;

void dfs(int u = 1) {
    s[u] = ++cnt;
    for (int v : adj[u]) dfs(v);
    e[u] = cnt;
}

int sum(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += bit[pos];
        pos &= (pos - 1);
    }
    return ret;
}

void add(int pos, int val) {
    while (pos < MAX) {
        bit[pos] += val;
        pos += (pos & -pos);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, parent;
    cin >> n >> m >> parent;
    for (int i = 2; i <= n; i++) {
        cin >> parent;
        adj[parent].push_back(i);
    }
    dfs();
    while (m--) {
        int t, i;
        cin >> t >> i;
        if (t == 1) {
            int w;
            cin >> w;
            add(s[i], w);
            add(e[i]+1, -w);
        } else {
            cout << sum(s[i]) << '\n';
        }
    }
    return 0;
}
