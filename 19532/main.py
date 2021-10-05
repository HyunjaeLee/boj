a, b, c, d, e, f = map(int, input().split())
y = (a*f - c*d) // (a*e - b*d)
x = (b*f - c*e) // (b*d - a*e)
print(x, y)
