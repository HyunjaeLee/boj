import sys
read = sys.stdin.readline
N, M = map(int, read().split())
memo = {}
for i in range(N):
    s = read().split()
    memo[s[0]] = s[1]
for i in range(M):
    print(memo[read().rstrip()])
