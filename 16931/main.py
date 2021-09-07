import sys
N, M = map(int, sys.stdin.readline().split())
blocks = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
def valid(row, col):
    return row >= 0 and row < N and col >= 0 and col < M
ds = ((1,0), (0,1), (-1,0), (0,-1))
area = N * M * 2
for i in range(N):
    for j in range(M):
        for d in ds:
            if valid(i+d[0], j+d[1]):
                area += max(blocks[i][j] - blocks[i+d[0]][j+d[1]], 0)
            else:
                area += blocks[i][j]
print(area)
