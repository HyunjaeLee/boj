table = [list(map(int, input().split())) for _ in range(9)]
big = 0
for i in range(9):
    for j in range(9):
        if table[i][j] > big:
            big = table[i][j]
            row, col = i+1, j+1
print(big)
print(row, col)
