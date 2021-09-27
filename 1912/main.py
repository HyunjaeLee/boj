import sys
read = sys.stdin.readline
n = int(read())
seq = list(map(int, read().split()))
acc = 0
ans = 0
for x in seq:
    acc = max(acc+x, 0)
    ans = max(acc, ans)
print(ans if ans > 0 else max(seq))
