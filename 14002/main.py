import sys
from bisect import bisect_left
read = sys.stdin.readline
read()
A = list(map(int, read().split()))
trace = []
length = 0
x = [(0, -1)]
for i, a in enumerate(A):
    if x[-1][0] < a:
        if len(x) > length:
            length = len(x)
            idx = i
        trace.append(x[-1][1])
        x.append((a, i))
    else:
        pos = bisect_left(x, (a,))
        trace.append(x[pos-1][1])
        x[pos] = (a, i)
print(length)
stk = [A[idx]]
loc = trace[idx]
while loc >= 0:
    stk.append(A[loc])
    loc = trace[loc]
print(' '.join(map(str, reversed(stk))))
