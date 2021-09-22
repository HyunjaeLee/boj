import sys
T = int(sys.stdin.readline())
for _ in range(T):
    s = sys.stdin.readline().split()
    num = float(s[0])
    for op in s[1:]:
        if op == '@':
            num *= 3
        elif op == '%':
            num += 5
        elif op == '#':
            num -= 7
    print('%.2f'%num)