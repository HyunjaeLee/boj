import sys
readln = sys.stdin.readline
t = int(readln())
for _ in range(t):
    n = int(readln())
    maxl = -1
    for _ in range(n):
        sp = readln().split()
        s = sp[0]
        l = int(sp[1])
        if l > maxl:
            maxl = l
            maxs = s
    print(maxs)
