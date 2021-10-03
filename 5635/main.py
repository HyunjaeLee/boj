a = []
for _ in range(int(input())):
    s = input().split()
    d, m, y = map(int, s[1:])
    a.append((y, m, d, s[0]))
a.sort()
print(a[-1][3])
print(a[0][3])
