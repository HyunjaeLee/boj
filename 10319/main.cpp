#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Edge {
    int target, capacity, flow;
    Edge * reverse;
    Edge(int t, int c) : target(t), capacity(c), flow(0) {}
    int residual() { return capacity - flow; }
    void push(int amount) {
        flow += amount;
        reverse->flow -= amount;
    }
};

const int VMAX = 101002, INF = (1<<30);
vector<Edge*> adj[VMAX];

void add_edge(int u, int v, int capacity) {
    Edge * uv = new Edge(v, capacity);
    Edge * vu = new Edge(u, 0);
    uv->reverse = vu;
    vu->reverse = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

void solve() {
    int n, start, g, s, m;
    cin >> n >> start >> g >> s >> m;
    int source = (s+1)*n, sink = (s+1)*n+1;
    add_edge(source, (s+1)*(start-1), g);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s; j++) {
            add_edge((s+1)*i+j, (s+1)*i+j+1, INF);
        }
    }
    while (m--) {
        int hospital;
        cin >> hospital;
        int u_zero = (s+1)*(hospital-1);
        for (int i = 0; i <= s; i++) {
            add_edge(u_zero+i, sink, INF);
        }
    }
    int r;
    cin >> r;
    while (r--) {
        int a, b, p, t;
        cin >> a >> b >> p >> t;
        int u_zero = (s+1)*(a-1), v_zero = (s+1)*(b-1);
        for (int i = 0; i <= s-t; i++) {
            add_edge(u_zero+i, v_zero+i+t, p);
        }
    }
    int total = 0;
    while (true) {
        vector<int> parent(sink+1, -1);
        parent[source] = source;
        queue<int> q;
        q.push(source);
        vector<Edge*> path(sink+1);
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();
            for (auto e : adj[u]) {
                int v = e->target;
                if (e->residual() > 0 && parent[v] == -1) {
                    parent[v] = u;
                    path[v] = e;
                    q.push(v);
                }
            }
        }
        if (parent[sink] == -1) break;
        int amount = INF;
        for (int i = sink; i != source; i = parent[i])
            amount = min(amount, path[i]->residual());
        for (int i = sink; i != source; i = parent[i])
            path[i]->push(amount);
        total += amount;
    }
    cout << total << '\n';
    for (int i = 0; i < VMAX; i++) {
        for (auto e : adj[i]) delete e;
        adj[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
