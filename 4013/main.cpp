#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 500'001;
int dp[MAX], id[MAX], id_cnt, scc[MAX], scc_cnt, cash[MAX];
bool rest[MAX];
stack<int> stk;
vector<int> adj[MAX];

int dfs(int u) {
    stk.push(u);
    int ret = id[u] = ++id_cnt;
    for (int v : adj[u]) {
        if (id[v] == -1) ret = min(ret, dfs(v));
        else if (scc[v] == -1) ret = min(ret, id[v]);
    }
    if (id[u] == ret) {
        bool has_rest = false;
        int scc_cash = 0;
        while (true) {
            int t = stk.top();
            stk.pop();
            scc_cash += cash[t];
            scc[t] = scc_cnt;
            if (rest[t]) has_rest = true;
            for (int e : adj[t]) {
                if (scc[e] == -1 || scc[e] == scc_cnt) continue;
                dp[scc_cnt] = max(dp[scc_cnt], dp[scc[e]]);
            }
            if (u == t) break;
        }
        if (has_rest || dp[scc_cnt]) dp[scc_cnt] += scc_cash;
        scc_cnt++;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        cin >> cash[i];
    }
    int S, P;
    cin >> S >> P;
    while (P--) {
        int a;
        cin >> a;
        rest[a] = true;
    }
    memset(id, -1, sizeof(int)*(N+1));
    memset(scc, -1, sizeof(int)*N);
    for (int i = 1; i <= N; i++) {
        if (id[i] == -1) dfs(i);
    }
    cout << dp[scc[S]] << '\n';
    return 0;
}
