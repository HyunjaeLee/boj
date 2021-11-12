#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R, C;
int grid[1000][1000];
int dr[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    grid[row][col] = 0;
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = pos.first + dr[i];
            int nc = pos.second + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }
            if (!grid[nr][nc]) {
                continue;
            }
            q.push({nr, nc});
            grid[nr][nc] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!grid[i][j]) continue;
            bfs(i, j);
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
