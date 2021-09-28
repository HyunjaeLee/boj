s = input()
while s != '#':
    print(s[0], s.lower().count(s[0], 2))
    s = input()
