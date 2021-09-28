N, a, b, c = [int(input()) for _ in range(4)]
if a == b == c:
    print(a)
elif 2*b == a + c:
    d = b - a
    print(a + N*d)
else:
    r = b // a
    print(a * r**N)
