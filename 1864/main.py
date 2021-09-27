import sys
table = {'-': 0, '\\': 1, '(': 2, '@': 3, '?': 4, '>': 5, '&': 6, '%': 7, '/': -1}
while True:
    s = sys.stdin.readline().rstrip()
    if s == '#':
        break
    n = 0
    for c in s:
        n = n * 8 + table[c]
    print(n)
