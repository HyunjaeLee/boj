import sys, bisect
read = sys.stdin.readline
read()
x = [0]
result = 0
for a in map(int, read().split()):
    if a > x[-1]:
        result = max(result, len(x))
        x.append(a)
    else:
        i = bisect.bisect_left(x, a)
        result = max(result, i)
        x[i] = a
print(result)
