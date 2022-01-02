#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
typedef long long ll;

struct SegTree {
    vector<ll> tree;
    int n;

    void init(vector<ll>& v, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft == nodeRight) {
            tree[node] = v[nodeLeft];
            return;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        init(v, 2*node, nodeLeft, mid);
        init(v, 2*node+1, mid+1, nodeRight);
        tree[node] = gcd(tree[2*node], tree[2*node+1]);
    }

    SegTree(vector<ll>& v) {
        n = v.size();
        tree.resize(4*n);
        init(v, 1, 0, n-1);
    }

    void update(int pos, ll val, int node, int nodeLeft, int nodeRight) {
        if (nodeRight < pos || pos < nodeLeft) return;
        if (nodeLeft == nodeRight) {
            tree[node] += val;
            return;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        update(pos, val, 2*node, nodeLeft, mid);
        update(pos, val, 2*node+1, mid+1, nodeRight);
        tree[node] = gcd(tree[2*node], tree[2*node+1]);
    }

    void update(int pos, ll val) {
        update(pos, val, 1, 0, n-1);
    }

    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (nodeRight < left || right < nodeLeft) return 0;
        if (left <= nodeLeft && nodeRight <= right) return tree[node];
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftQuery = query(left, right, 2*node, nodeLeft, mid);
        ll rightQuery = query(left, right, 2*node+1, mid+1, nodeRight);
        return gcd(leftQuery, rightQuery);
    }

    ll query(int left, int right) {
        if (left > right) return 0;
        return query(left, right, 1, 0, n-1);
    }
};

struct FenwickTree {
    vector<ll> tree;

    ll sum(int pos) {
        ll ret = 0;
        ++pos;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, ll val) {
        ++pos;
        while (pos < (int)tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }

    FenwickTree(vector<ll>& v) {
        int n = v.size();
        tree.resize(n+1);
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<ll> v(N);
    for (auto& e : v) cin >> e;
    vector<ll> d(N+1);
    d[0] = v[0];
    for (int i = 1; i < N; i++) {
        d[i] = v[i] - v[i-1];
    }
    int Q;
    cin >> Q;
    SegTree seg(d);
    FenwickTree bit(d);
    while (Q--) {
        int T, A, B;
        cin >> T >> A >> B;
        if (T) {
            seg.update(A-1, T);
            seg.update(B, -T);
            bit.add(A-1, T);
            bit.add(B, -T);
        } else {
            cout << gcd(bit.sum(A-1), seg.query(A, B-1)) << '\n';
        }
    }
    return 0;
}
