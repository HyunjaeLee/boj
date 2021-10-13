for _ in range(int(input())):
    s = input()
    l = s.lower()
    g = l.count('g')
    b = l.count('b')
    if g > b:
        print(s, 'is GOOD')
    elif g < b:
        print(s, 'is A BADDY')
    else:
        print(s, 'is NEUTRAL')
