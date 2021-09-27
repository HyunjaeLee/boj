import sys, bisect
read = sys.stdin.readline
read()
A = list(map(int, read().split()))
def lis(seq):
    x = [0]
    result = []
    for a in seq:
        if a > x[-1]:
            result.append(len(x))
            x.append(a)
        else:
            i = bisect.bisect_left(x, a)
            result.append(i)
            x[i] = a
    return result
print(max(map(lambda x, y: x+y-1, lis(A), reversed(lis(reversed(A))))))
