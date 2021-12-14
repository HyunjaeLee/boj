#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class MergeSortTree {
private:
    int n;
    vector<vector<int>> tree;
    void init(vector<int>& v, int node, int nodeLeft, int nodeRight);
    int query(int left, int right, int val, int node, int nodeLeft, int nodeRight);
public:
    MergeSortTree(vector<int>& v);
    int query(int left, int right, int val);
};

void MergeSortTree::init(vector<int>& v, int node, int nodeLeft, int nodeRight) {
    if (nodeLeft == nodeRight) {
        tree[node].push_back(v[nodeLeft]);
        return;
    }
    int mid = (nodeLeft + nodeRight) / 2;
    init(v, 2*node, nodeLeft, mid);
    init(v, 2*node+1, mid+1, nodeRight);
    vector<int>& lvec = tree[2*node];
    vector<int>& rvec = tree[2*node+1];
    int lsize = lvec.size();
    int rsize = rvec.size();
    tree[node].resize(lsize+rsize);
    int pos = 0, lpos = 0, rpos = 0;
    while (lpos < lsize && rpos < rsize) {
        if (lvec[lpos] < rvec[rpos]) tree[node][pos++] = lvec[lpos++];
        else tree[node][pos++] = rvec[rpos++];
    }
    while (lpos < lsize) tree[node][pos++] = lvec[lpos++];
    while (rpos < rsize) tree[node][pos++] = rvec[rpos++];
}

int MergeSortTree::query(int left, int right, int val, int node, int nodeLeft, int nodeRight) {
    if (nodeRight < left || right < nodeLeft) return 0;
    if (left <= nodeLeft && nodeRight <= right) return lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
    int mid = (nodeLeft + nodeRight) / 2;
    return query(left, right, val, 2*node, nodeLeft, mid) + query(left, right, val, 2*node+1, mid+1, nodeRight);
}

MergeSortTree::MergeSortTree(vector<int>& v) {
    n = v.size();
    tree.resize(4*n);
    init(v, 1, 0, n-1);
}

int MergeSortTree::query(int left, int right, int val) {
    return query(left, right, val, 1, 0, n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int& e : v) cin >> e;
    MergeSortTree tree(v);
    sort(v.begin(), v.end());
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        --i; --j;
        int left = 0, right = n;
        while (left+1 < right) {
            int mid = (left + right) / 2;
            if (tree.query(i, j, v[mid]) < k) left = mid;
            else right = mid;
        }
        cout << v[left] << '\n';
    }
    return 0;
}
