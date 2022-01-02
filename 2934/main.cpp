#include <iostream>
using namespace std;

const int MAX = 100'002;
int bit[MAX];

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
    int N;
    cin >> N;
    while (N--) {
        int L, R;
        cin >> L >> R;
        int flower_left = sum(L);
        int flower_right = sum(R);
        cout << flower_left + flower_right << '\n';
        add(L, -flower_left);
        add(L+1, flower_left);
        add(R, -flower_right);
        add(R+1, flower_right);
        add(L+1, 1);
        add(R, -1);
    }
    return 0;
}
