#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
    vector<ll> lazy;
    void update(int left, int right, ll value, int node, int nodeLeft, int nodeRight);
    ll query(int left, int right, int node, int nodeLeft, int nodeRight);
    void init(const vector<ll>& v, int node, int left, int right);
    void propagate(int node, int nodeLeft, int nodeRight);
public:
    SegmentTree(const vector<ll>& v);
    void update(int left, int right, ll value);
    ll query(int left, int right);
};

ll SegmentTree::query(int left, int right) {
    return query(left, right, 1, 0, n-1);
}

ll SegmentTree::query(int left, int right, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);
    if (nodeRight < left || right < nodeLeft) {
        return 0;
    }
    if (left <= nodeLeft && nodeRight <= right) {
        return tree[node];
    }
    int mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, 2*node, nodeLeft, mid) + query(left, right, 2*node+1, mid+1, nodeRight);
}

void SegmentTree::update(int left, int right, ll value) {
    update(left, right, value, 1, 0, n-1);
}

void SegmentTree::update(int left, int right, ll value, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);
    if (nodeRight < left || right < nodeLeft) {
        return;
    }
    if (left <= nodeLeft && nodeRight <= right) {
        lazy[node] = value;
        propagate(node, nodeLeft, nodeRight);
        return;
    }
    int mid = (nodeLeft + nodeRight) / 2;
    update(left, right, value, 2*node, nodeLeft, mid);
    update(left, right, value, 2*node+1, mid+1, nodeRight);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void SegmentTree::propagate(int node, int nodeLeft, int nodeRight) {
    if (!lazy[node]) {
        return;
    }
    if (nodeLeft != nodeRight) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    tree[node] += lazy[node] * (nodeRight-nodeLeft+1);
    lazy[node] = 0;
}

void SegmentTree::init(const vector<ll>& v, int node, int left, int right) {
    if (left == right) {
        tree[node] = v[left];
        return;
    }
    int mid = (left + right) / 2;
    init(v, 2*node, left, mid);
    init(v, 2*node+1, mid+1, right);
    tree[node] = tree[2*node] + tree[2*node+1];
}

SegmentTree::SegmentTree(const vector<ll>& v) {
    n = v.size();
    tree.resize(4*n);
    lazy.resize(4*n);
    init(v, 1, 0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> v(N);
    for (ll& e : v) {
        cin >> e;
    }
    SegmentTree st(v);
    int a, b, c;
    ll d;
    for (int i = 0; i < M+K; i++) {
        cin >> a >> b >> c;
        switch (a) {
        case 1:
            cin >> d;
            st.update(b-1, c-1, d);
            break;
        case 2:
            cout << st.query(b-1, c-1) << '\n';
            break;
        }
    }
    return 0;
}
