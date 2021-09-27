import sys
s = sys.stdin.readline().rstrip()
while s != '#':
    cnt = 0
    for c in s:
        if c in 'aeiouAEIOU':
            cnt += 1
    print(cnt)
    s = sys.stdin.readline().rstrip()
