#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree {
    vector<int> tree;

    FenwickTree(int n) : tree(n+1) {}

    int sum(int pos) {
        ++pos;
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos) {
        ++pos;
        while (pos < int(tree.size())) {
            ++tree[pos];
            pos += (pos & -pos);
        }
    }
};

struct Point {
    int x, y, sum;
    bool operator<(const Point& p) const { return sum > p.sum; }
};

struct Query {
    int id, x, y, sum;
    bool operator<(const Query& q) const { return sum > q.sum; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<Point> points(N);
    vector<int> comp_x, comp_y;
    for (auto& p : points) {
        cin >> p.x >> p.y;
        comp_x.push_back(p.x);
        comp_y.push_back(p.y);
        p.sum = p.x + p.y;
    }
    sort(points.begin(), points.end());
    sort(comp_x.begin(), comp_x.end());
    sort(comp_y.begin(), comp_y.end());
    comp_x.erase(unique(comp_x.begin(), comp_x.end()), comp_x.end());
    comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());
    const int XMAX = comp_x.size();
    const int YMAX = comp_y.size();
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        auto& q = queries[i];
        q.id = i;
        cin >> q.x >> q.y >> q.sum;
        q.sum = max(q.x+q.y, q.sum);
    }
    sort(queries.begin(), queries.end());
    FenwickTree xbit(XMAX), ybit(YMAX);
    vector<int> result(Q);
    auto it = points.begin();
    for (auto& q : queries) {
        while (it != points.end() && it->sum >= q.sum) {
            int x = lower_bound(comp_x.begin(), comp_x.end(), it->x) - comp_x.begin();
            int y = lower_bound(comp_y.begin(), comp_y.end(), it->y) - comp_y.begin();
            xbit.add(x);
            ybit.add(y);
            ++it;
        }
        int x = lower_bound(comp_x.begin(), comp_x.end(), q.x) - comp_x.begin();
        int y = lower_bound(comp_y.begin(), comp_y.end(), q.y) - comp_y.begin();
        result[q.id] = ybit.sum(YMAX-1) - ybit.sum(y-1) - xbit.sum(x-1);
    }
    for (int a : result) cout << a << '\n';
    return 0;
}
