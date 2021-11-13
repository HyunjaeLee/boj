#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
    const int MOD = 1'000'000'007;
    int n;
    vector<ll> ser;
    ll init(const vector<ll>& v, int left, int right, int node);
    ll query(int left, int right, int node, int node_left, int node_right);
    ll update(int index, ll new_value, int node, int node_left, int node_right);
public:
    SegmentTree(const vector<ll>& v);
    ll query(int left, int right);
    void update(int index, ll new_value);
};

void SegmentTree::update(int index, ll new_value) {
    update(index, new_value, 1, 0, n-1);
}

ll SegmentTree::update(int index, ll new_value, int node, int node_left, int node_right) {
    if (index < node_left || node_right < index) {
        return ser[node];
    }
    if (node_left == node_right) {
        return ser[node] = new_value;
    }
    int mid = (node_left + node_right) / 2;
    ll lres = update(index, new_value, 2*node, node_left, mid);
    ll rres = update(index, new_value, 2*node+1, mid+1, node_right);
    return ser[node] = lres * rres % MOD;
}

ll SegmentTree::query(int left, int right) {
    return query(left, right, 1, 0, n-1);
}

ll SegmentTree::query(int left, int right, int node, int node_left, int node_right) {
    if (right < node_left || node_right < left) {
        return 1;
    }
    if (left <= node_left && node_right <= right) {
        return ser[node];
    }
    int mid = (node_left + node_right) / 2;
    return query(left, right, 2*node, node_left, mid) * query(left, right, 2*node+1, mid+1, node_right) % MOD;
}

SegmentTree::SegmentTree(const vector<ll>& v) {
    n = v.size();
    ser.resize(4*n);
    init(v, 0, n-1, 1);
}

ll SegmentTree::init(const vector<ll>& v, int left, int right, int node) {
    if (left==right) {
        return ser[node] = v[left];
    }
    int mid = (left + right) / 2;
    ll lres = init(v, left, mid, 2*node);
    ll rres = init(v, mid+1, right, 2*node+1);
    return ser[node] = lres * rres % MOD;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> v(N);
    for (auto& e : v) {
        cin >> e;
    }
    SegmentTree seg(v);
    int a, b, c;
    for (int i = 0; i < M+K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            seg.update(b-1, c);
        } else {
            cout << seg.query(b-1, c-1) << '\n';
        }
    }
    return 0;
}
