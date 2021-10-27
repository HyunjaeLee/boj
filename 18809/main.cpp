#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

const int GREEN = (1 << 30);
const int RED = (1 << 29);
const int FLOWER = (1 << 28);
const int MASK = (1<<29) - 1;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
int N, M, G, R;
int garden[50][50];
int trace[50][50];

void clear_trace() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            trace[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> G >> R;
    vector<pair<int, int>> yellow;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> garden[i][j];
            if (garden[i][j] == 2) {
                yellow.push_back({i, j});
            }
        }
    }
    vector<int> comb;
    for (int i = 0; i < yellow.size()-G-R; i++) {
        comb.push_back(0);
    }
    for (int i = 0; i < G; i++) {
        comb.push_back(1);
    }
    for (int i = 0; i < R; i++) {
        comb.push_back(2);
    }
    int max_flower = -1;
    do {
        clear_trace();
        queue<pair<int, int>> q;
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 1) {
                trace[yellow[i].first][yellow[i].second] = GREEN;
                q.push(yellow[i]);
            } else if (comb[i] == 2) {
                trace[yellow[i].first][yellow[i].second] = RED;
                q.push(yellow[i]);
            }
        }
        int flower = 0;
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            if (trace[pos.first][pos.second] == FLOWER) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M || !garden[nr][nc]) {
                    continue;
                }
                if ((trace[nr][nc]|MASK) != (trace[pos.first][pos.second]|MASK) && (trace[nr][nc]&MASK) == (trace[pos.first][pos.second]&MASK)+1) {
                    trace[nr][nc] = FLOWER;
                    flower++;
                    continue;
                }
                if (trace[nr][nc]) {
                    continue;
                }
                trace[nr][nc] = trace[pos.first][pos.second] + 1;
                q.push({nr, nc});
            }
        }
        max_flower = max(max_flower, flower);
    } while (next_permutation(comb.begin(), comb.end()));
    cout << max_flower << '\n';
    return 0;
}
