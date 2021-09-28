import sys
read = sys.stdin.readline
read()
A = list(map(int, read().split()))
dp = []
for v in A:
    sum = 0
    for pair in reversed(dp):
        if pair[1] < v:
            sum = max(sum, pair[0])
    dp.append((sum+v, v))
print(max(dp)[0])
