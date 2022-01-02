#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100'001, MOST = 30;
int table[MOST][MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> v(N);
    for (int& e : v) cin >> e;
    for (int i = 1; i <= K; i++) {
        cin >> table[0][i];
    }
    for (int i = 1; i < MOST; i++) {
        for (int j = 1; j <= K; j++) {
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    M--;
    for (int x : v) {
        for (int i = 0; i < MOST; i++) {
            if (M & (1<<i)) x = table[i][x];
        }
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
