n = int(input())
for _ in range(n):
    p = int(input())
    max_price = 0
    for _ in range(p):
        s = input().split()
        price = int(s[0])
        if price > max_price:
            max_price = price
            name = s[1]
    print(name)
