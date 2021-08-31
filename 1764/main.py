import sys
N, M = map(int, sys.stdin.readline().split())
set_N = set()
set_M = set()
for _ in range(N):
    set_N.add(sys.stdin.readline().rstrip())
for _ in range(M):
    set_M.add(sys.stdin.readline().rstrip())
ans = sorted(set_M & set_N)
print(len(ans))
for name in ans:
    print(name)
