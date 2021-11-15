#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
    vector<ll> lazy;
    void init(const vector<int>& v, int node, int nodeLeft, int nodeRight);
    void propagate(int node, int nodeLeft, int nodeRight);
    void update(int left, int right, int val, int node, int nodeLeft, int nodeRight);
    ll query(int left, int right, int node, int nodeLeft, int nodeRight);
public:
    SegmentTree(const vector<int>& v);
    void update(int left, int right, int val);
    ll query(int left, int right);
};

void SegmentTree::init(const vector<int>& v, int node, int nodeLeft, int nodeRight) {
    if (nodeLeft == nodeRight) {
        tree[node] = v[nodeLeft];
        return;
    }
    int mid = (nodeLeft + nodeRight) / 2;
    init(v, 2*node, nodeLeft, mid);
    init(v, 2*node+1, mid+1, nodeRight);
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

void SegmentTree::update(int left, int right, int val, int node, int nodeLeft, int nodeRight) {
    propagate(node, nodeLeft, nodeRight);
    if (nodeRight < left || right < nodeLeft) {
        return;
    }
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

SegmentTree::SegmentTree(const vector<int>& v) {
    n = v.size();
    tree.resize(4*n);
    lazy.resize(4*n);
    init(v, 1, 0, n-1);
}

void SegmentTree::update(int left, int right, int val) {
    update(left, right, val, 1, 0, n-1);
}

ll SegmentTree::query(int left, int right) {
    return query(left, right, 1, 0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    vector<int> v(N+1);
    for (int i = 1; i <= N; i++) {
        v[i] = arr[i] - arr[i-1];
    }
    int Q;
    cin >> Q;
    SegmentTree st(v);
    int a, b, c;
    while (Q--) {
        cin >> a >> b;
        switch (a) {
        case 1:
            cin >> c;
            st.update(b, c, 1);
            if (c < N) {
                st.update(c+1, c+1, b-c-1);
            }
            break;
        case 2:
            cout << st.query(1, b) << '\n';
            break;
        }
    }
    return 0;
}
